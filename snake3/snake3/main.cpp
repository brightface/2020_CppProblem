
#include <iostream>
#include <ncurses.h>
#include <curses.h>
#include <random>
#include <time.h>
#include <exception>
#include <stdexcept>
#include <vector>
#include <chrono>
#include <unistd.h>
using namespace std;

using menu_item_t = int;
#define Max_Length 20
#define Mission_Score 10
#define Mission_Growth 5
#define Mission_Poison 2
#define Mission_Gate 1

struct Point
{
	int y;
	int x;
};

//vector<Point> field_size_set = {{21, 29}, {36, 36}, {27, 27}, {31, 31}};

int Growth_num = 0;
int Poison_num = 0;
int Gate_num = 0;
int Score = 0;
int Mission_complete = 0;
time_t gamestarttime;

int flag = 0;
int GateFlag[2];
Point Gate[2];

//enum class eDirecton {STOP = 0, LEFT,RIGHT, UP, DOWN}; // Controls
struct MenuItem
{
	std::string label;
	Point pos;
};
class Settings
{
private:
	Settings() {};
public:
	static Point field_size;

};
enum class Object { empty, wall, Immune_Wall, player_head, player_tail, Growth, Poison, Gate, Gate_Pass };
enum class Facing { right, down, left, up, null };
class Player
{
private:
	std::vector<Point> m_position{ {5, 5}, {5, 4}, {5, 3} };
	unsigned int m_length = 3;
	Facing m_facing = Facing::right;
public:
	void Gatemove();
	void move(Point p_field_size);
	void lengthen() { ++m_length; };
	void shorthen() { --m_length; };
	Point get(unsigned int p_at = 0) { return m_position.at(p_at); }

	Facing get_facing() { return m_facing; }
	void set_facing(Facing p_facing);

	// returns the amount of Points the player occupies (costly!)
	int size() { return m_position.size(); }

	// returns the player's length. size() may have not been updated to it yet
	unsigned int length() { return m_length; }

};
class Field
{
	//private:

public:
	Object **m_field;
	Field();
	~Field();
	const Point m_field_size;

	Object get(Point p_point) const { return m_field[p_point.y][p_point.x]; }
	void set(Point p_point, Object p_object) { m_field[p_point.y][p_point.x] = p_object; }

	void place_growth_item();
	void place_poison_item();
	void add_walls();
	void update_player(Player *p_player);
	void settingGate(int numOfgate);
};

class MainMenu
{
private:
	template<typename Functor>
	void display_menu(std::vector<MenuItem> &p_menu_items, Functor p_selected_item_handler, bool p_quit_with_q, std::string p_title = "m_position");
	void new_game();
	void show_settings();
public:
	MainMenu();
	~MainMenu();
	void show();
};
class GameUI
{
private:
	WINDOW *m_border_win, *m_field_win;
	const Field *m_field;

	void update_field();
public:
	GameUI(WINDOW *p_border_win, WINDOW *p_field_win);

	void next_game();
	void set_field(Field *p_field) { m_field = p_field; };
	void draw_border();
	void draw_static_elements();
	void update(int score);
	Facing get_input();

};

class UIUtils
{
private:
	UIUtils() {};
public:
	static menu_item_t dialogbox(std::string p_text, std::vector<std::string> p_buttons);
};

struct GameEndDeath : std::exception {};
struct GameEndQuit : std::exception {};

class Game
{
private:
	GameUI *m_ui;
	Field *m_field;
	Player *m_player;

	void tick();
	void update();
public:
	Game(GameUI *p_ui);
	~Game();

	void start();
};

void Player::Gatemove()
{
	if ((m_position[0].x == Gate[0].x && m_position[0].y == Gate[0].y)) {
		switch (GateFlag[1]) {
		case 0:  //left
		{
			m_position.insert(m_position.begin(), { Gate[1].y, Gate[1].x + 1 });
			set_facing(Facing::right);
			break;
		}
		case 1:  //right
		{
			m_position.insert(m_position.begin(), { Gate[1].y, Gate[1].x - 1 });
			set_facing(Facing::left);
			break;
		}
		case 2:  //up
		{
			m_position.insert(m_position.begin(), { Gate[1].y + 1, Gate[1].x });
			set_facing(Facing::down);
			break;
		}
		case 3:  //down
		{
			m_position.insert(m_position.begin(), { Gate[1].y - 1, Gate[1].x });
			set_facing(Facing::up);
			break;
		}
		default:
			break;
		}
	}
	else {
		switch (GateFlag[0]) {
		case 0:  //left
		{
			m_position.insert(m_position.begin(), { Gate[0].y, Gate[0].x + 1 });
			set_facing(Facing::right);
			break;
		}
		case 1:  //right
		{
			m_position.insert(m_position.begin(), { Gate[0].y, Gate[0].x - 1 });
			set_facing(Facing::left);
			break;
		}
		case 2:  //up
		{
			m_position.insert(m_position.begin(), { Gate[0].y + 1, Gate[0].x });
			set_facing(Facing::down);
			break;
		}
		case 3:  //down
		{
			m_position.insert(m_position.begin(), { Gate[0].y - 1, Gate[0].x });
			set_facing(Facing::up);
			break;
		}
		default:
			break;
		}
	}
}

void Player::move(Point p_field_size)
{
	switch (m_facing)
	{
	case Facing::right:
	{

		if (m_position[0].x + 1 == p_field_size.x)
			throw GameEndDeath();
		else
			m_position.insert(m_position.begin(), { m_position.front().y, m_position.front().x + 1 });
		break;
	}
	case Facing::down:
	{

		if (m_position[0].y + 1 == p_field_size.y)
			throw GameEndDeath();
		else
			m_position.insert(m_position.begin(), { m_position.front().y + 1, m_position.front().x });
		break;
	}
	case Facing::left:
	{

		if (m_position[0].x - 1 == -1)
			throw GameEndDeath();
		else
			m_position.insert(m_position.begin(), { m_position.front().y, m_position.front().x - 1 });
		break;
	}
	case Facing::up:
	{

		if (m_position[0].y - 1 == -1)
			throw GameEndDeath();
		else
			m_position.insert(m_position.begin(), { m_position.front().y - 1, m_position.front().x });
		break;
	}
	default:
	{
		throw std::invalid_argument("Player has wrong Facing");
	}
	}

	while (m_position.size() > m_length) m_position.pop_back();
}

void Player::set_facing(Facing p_facing)
{
	switch (p_facing)
	{
	case Facing::right:
		if (m_facing != Facing::left) m_facing = p_facing;
		break;
	case Facing::left:
		if (m_facing != Facing::right) m_facing = p_facing;
		break;
	case Facing::down:
		if (m_facing != Facing::up) m_facing = p_facing;
		break;
	case Facing::up:
		if (m_facing != Facing::down) m_facing = p_facing;
		break;
	default:
		break;
	}
}

Field::Field() : m_field_size(Settings::field_size)  // 필드 초기화 "0"
{
	m_field = new Object*[m_field_size.y];
	for (int row = 0; row < m_field_size.y; ++row)
	{
		m_field[row] = new Object[m_field_size.x];
	}

	for (int y = 0; y < m_field_size.y; ++y)
	{
		for (int x = 0; x < m_field_size.x; ++x)
		{
			m_field[y][x] = Object::empty;
		}
	}

}

Field::~Field()
{
	for (int row = 0; row < m_field_size.y; ++row) delete[] m_field[row];
	delete[] m_field;
}

void Field::place_growth_item()
{
	while (true)
	{
		static std::mt19937 rng;
		rng.seed(std::random_device()());
		std::uniform_int_distribution<std::mt19937::result_type> disty(0, m_field_size.y - 1);
		std::uniform_int_distribution<std::mt19937::result_type> distx(0, m_field_size.x - 1);

		Point new_food = { (int)disty(rng), (int)distx(rng) };
		if (m_field[new_food.y][new_food.x] == Object::empty)
		{
			m_field[new_food.y][new_food.x] = Object::Growth;
			break;
		}

	}
}
void Field::place_poison_item()
{
	while (true)
	{
		static std::mt19937 rng;
		rng.seed(std::random_device()());
		std::uniform_int_distribution<std::mt19937::result_type> disty(0, m_field_size.y - 1);
		std::uniform_int_distribution<std::mt19937::result_type> distx(0, m_field_size.x - 1);

		Point new_poison = { (int)disty(rng), (int)distx(rng) };
		if (m_field[new_poison.y][new_poison.x] == Object::empty)
		{
			m_field[new_poison.y][new_poison.x] = Object::Poison;
			break;
		}

	}
}
void Field::add_walls()
{
	m_field[0][0] = Object::Immune_Wall;
	m_field[0][m_field_size.x - 1] = Object::Immune_Wall;
	m_field[m_field_size.y - 1][0] = Object::Immune_Wall;
	m_field[m_field_size.y - 1][m_field_size.x - 1] = Object::Immune_Wall;

	for (int y = 1; y < m_field_size.y - 1; ++y)
	{
		m_field[y][0] = Object::wall;
		m_field[y][m_field_size.x - 1] = Object::wall;
	}

	for (int x = 1; x < m_field_size.x - 1; ++x)
	{
		m_field[0][x] = Object::wall;
		m_field[m_field_size.y - 1][x] = Object::wall;
	}
	settingGate(0);
	settingGate(1);
	//게이트가 같으면 다시 게이트를 만든다.
	while (GateFlag[1] == GateFlag[0]) {
		settingGate(1);
	}

	m_field[Gate[0].y][Gate[0].x] = Object::Gate;
	m_field[Gate[1].y][Gate[1].x] = Object::Gate;
}

void Field::settingGate(int numOfgate)
{
	GateFlag[numOfgate] = 0;
	Gate[numOfgate].y = 0;
	Gate[numOfgate].x = 0;

	srand(time(NULL));
	GateFlag[numOfgate] = rand() % 4;
	//게이트가 왼쪽에 생길때
	if (GateFlag[numOfgate] == 0) {
		Gate[numOfgate].y = rand() % (m_field_size.y - 2) + 1;
		Gate[numOfgate].x = 0;
	}
	//게이트가 오른쪽에생길떄
	else if (GateFlag[numOfgate] == 1) {
		Gate[numOfgate].y = rand() % (m_field_size.y - 2) + 1;
		Gate[numOfgate].x = m_field_size.x - 1;
	}
	//게이트가 위에 생길때
	else if (GateFlag[numOfgate] == 2) {
		Gate[numOfgate].y = 0;
		Gate[numOfgate].x = rand() % (m_field_size.x - 2) + 1;
	}
	//게이트가 아래에 생길때
	else {
		Gate[numOfgate].y = m_field_size.y - 1;
		Gate[numOfgate].x = rand() % (m_field_size.x - 2) + 1;
	}
}

void Field::update_player(Player *p_player)
{
	if (flag == 0)
	{
		for (int row = 0; row < m_field_size.y; ++row)
		{
			for (int col = 0; col < m_field_size.x; ++col)
			{
				if (m_field[row][col] == Object::player_head || m_field[row][col] == Object::player_tail)
				{
					m_field[row][col] = Object::empty;
				}
			}
		}
	}
	else
	{
		for (int row = 0; row < m_field_size.y; ++row)
		{
			for (int col = 0; col < m_field_size.x; ++col)
			{
				if (m_field[row][col] == Object::player_head || m_field[row][col] == Object::player_tail)
				{
					m_field[row][col] = Object::Gate_Pass;
				}
			}
		}

	}

	Point player_point = p_player->get(0);
	m_field[player_point.y][player_point.x] = Object::player_head;
	for (int i = 1; i < p_player->size(); ++i)
	{
		Point player_point = p_player->get(i);
		m_field[player_point.y][player_point.x] = Object::player_tail;
	}
}



struct GameExit : std::exception {};

template<typename Functor>
void MainMenu::display_menu(std::vector<MenuItem> &p_menu_items, Functor p_selected_item_handler, bool p_quit_with_q, std::string p_title)
{
	for (std::size_t i = 0; i < p_menu_items.size(); ++i)
	{
		p_menu_items[i].pos = { LINES / 2 + (int)i,
							(COLS - (int)p_menu_items[i].label.length()) / 2 };
	}

	try
	{
		erase();
		menu_item_t selected_item = 0;
		bool is_selected = false;
		while (true)
		{
			mvprintw(LINES / 4, (COLS - p_title.length()) / 2, p_title.c_str());

			for (std::size_t i = 0; i < p_menu_items.size(); ++i)
			{
				mvprintw(p_menu_items[i].pos.y, p_menu_items[i].pos.x, p_menu_items[i].label.c_str());
			}

			// make the currently selected item standout
			mvchgat(p_menu_items[selected_item].pos.y, p_menu_items[selected_item].pos.x, p_menu_items[selected_item].label.length(), A_STANDOUT, 0, NULL);
			refresh();

			switch (getch())
			{
			case KEY_UP:
				selected_item = selected_item != 0 ? selected_item - 1 : p_menu_items.size() - 1;
				break;
			case KEY_DOWN:
				selected_item = selected_item != (int)p_menu_items.size() - 1 ? selected_item + 1 : 0;
				break;
			case '\n':
				is_selected = true;
				break;
			case 'q':
			case 27:
				if (p_quit_with_q) throw GameExit();
				break;
			}

			if (is_selected)
			{
				p_selected_item_handler(selected_item);
				is_selected = false;
				erase();
			}
		}
	}
	// exit the game, if it's called for an exit
	catch (const GameExit &) {}
}

void MainMenu::new_game()
{
	erase();
	refresh();
	//Point Settings::field_size = field_size_set[0];
	WINDOW *game_win = newwin(Settings::field_size.y + 2, Settings::field_size.x + 2, (LINES - Settings::field_size.y) / 2 - 1, (COLS - Settings::field_size.x) / 2 - 1);
	WINDOW *game_field_win = newwin(Settings::field_size.y, Settings::field_size.x + 16, (LINES - Settings::field_size.y) / 2, (COLS - (Settings::field_size.x)) / 2);
	GameUI *game_ui = new GameUI(game_win, game_field_win);
	//GameUI game_ui{game_win, game_field_win};
	Game game(game_ui);

	gamestarttime = time(NULL);
	game.start();

	delwin(game_field_win);
	delwin(game_win);
	delete game_ui;
}

void MainMenu::show_settings()
{
	std::vector<MenuItem> settings_menu_items = { {
												{std::string("Field size: ") + std::to_string(Settings::field_size.y) + " rows, " + std::to_string(Settings::field_size.x) + " cols"},
												} };
	display_menu(settings_menu_items,
		[&settings_menu_items](menu_item_t p_selected_item)
	{
		switch (p_selected_item)
		{
		case 0:
			switch (Settings::field_size.y)
			{
			case 21:
				Settings::field_size = { 25, 50 };
				break;
			case 25:
				Settings::field_size = { 30, 25 };
				break;
			default:
				Settings::field_size = { 21, 35 };
				break;
			}
			settings_menu_items[0].label = std::string("Field size: ") + std::to_string(Settings::field_size.y) + " rows, " + std::to_string(Settings::field_size.x) + " cols";
			break;
		default:
			break;
		}
	},
		true, "Settings");
}

MainMenu::MainMenu()
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);

	keypad(stdscr, true);
}

MainMenu::~MainMenu()
{
	endwin();
}

void MainMenu::show()
{
	std::vector<MenuItem> main_menu_items = { {
											{"New Game", {} },
											{"Settings", {} },
											{"Exit", {} }
											} };

	display_menu(main_menu_items,
		[this](menu_item_t p_selected_item)
	{
		switch (p_selected_item)
		{
			// New Game
		case 0:
			new_game();
			break;
			// Settings
		case 1:
			show_settings();
			break;
		case 2:
			throw GameExit();
		}
	}, false);
}
GameUI::GameUI(WINDOW *p_border_win, WINDOW *p_field_win) : m_border_win(p_border_win), m_field_win(p_field_win)
{
	//draw_border();
	nodelay(m_field_win, true);
	keypad(m_field_win, true);
}


void GameUI::draw_static_elements()
{
	for (int row = 0; row < m_field->m_field_size.y; ++row)
	{
		for (int col = 0; col < m_field->m_field_size.x; ++col)
		{
			if (m_field->get({ row, col }) == Object::wall || m_field->get({ row, col }) == Object::Gate_Pass) mvwaddch(m_field_win, row, col, '1');
			else if (m_field->get({ row, col }) == Object::Immune_Wall) mvwaddch(m_field_win, row, col, '2');
		}
	}
	if (m_field->get(Gate[0]) == Object::empty) mvwaddch(m_field_win, Gate[0].y, Gate[0].x, '1');
	else if (m_field->get(Gate[1]) == Object::empty) mvwaddch(m_field_win, Gate[1].y, Gate[1].x, '1');
	wrefresh(m_field_win);
}

void GameUI::update(int score)
{
	mvwprintw(m_field_win, 1, Settings::field_size.x + 2, "Score Board");
	mvwprintw(m_field_win, 2, Settings::field_size.x + 2, "Score: %d / %d", score, Max_Length);
	mvwprintw(m_field_win, 3, Settings::field_size.x + 2, "+: %d", Growth_num);
	mvwprintw(m_field_win, 4, Settings::field_size.x + 2, "-: %d", Poison_num);
	mvwprintw(m_field_win, 5, Settings::field_size.x + 2, "G: %d", Gate_num);
	mvwprintw(m_field_win, 8, Settings::field_size.x + 2, "Mission");
	if (score >= Mission_Score)
	{
		mvwprintw(m_field_win, 9, Settings::field_size.x + 2, "Score: %d  (%c)", Mission_Score, 'v');
		Mission_complete++;
	}
	else
		mvwprintw(m_field_win, 9, Settings::field_size.x + 2, "Score: %d  ( )", Mission_Score);
	if (Growth_num >= Mission_Growth)
	{
		mvwprintw(m_field_win, 10, Settings::field_size.x + 2, "+: %d  (%c)", Mission_Growth, 'v');
		Mission_complete++;
	}
	else
		mvwprintw(m_field_win, 10, Settings::field_size.x + 2, "+: %d  ( )", Mission_Growth);
	if (Poison_num >= Mission_Poison)
	{
		mvwprintw(m_field_win, 11, Settings::field_size.x + 2, "-: %d  (%c)", Mission_Poison, 'v');
		Mission_complete++;
	}
	else
		mvwprintw(m_field_win, 11, Settings::field_size.x + 2, "-: %d  ( )", Mission_Poison);
	if (Gate_num >= Mission_Gate)
	{
		mvwprintw(m_field_win, 12, Settings::field_size.x + 2, "G: %d  (%c)", Mission_Gate, 'v');
		Mission_complete++;
	}
	else
		mvwprintw(m_field_win, 12, Settings::field_size.x + 2, "G: %d  ( )", Mission_Gate);

	mvwprintw(m_field_win, 13, Settings::field_size.x + 2, "time: %f", (double)(time(NULL) - gamestarttime));

	wrefresh(m_field_win);
	update_field();
	wrefresh(m_field_win);

	//if (Mission_complete == 4) {


	//  next_game();
	//}
}
void GameUI::update_field()
{
	draw_static_elements();
	for (int row = 0; row < m_field->m_field_size.y; ++row)
	{
		for (int col = 0; col < m_field->m_field_size.x; ++col)
		{
			switch (m_field->get({ row, col }))
			{
			case Object::empty:
				mvwaddch(m_field_win, row, col, '0');
				break;
			case Object::player_head:
				mvwaddch(m_field_win, row, col, '3');
				break;
			case Object::player_tail:
				mvwaddch(m_field_win, row, col, '4');
				break;
			case Object::Growth:
				mvwaddch(m_field_win, row, col, '5');
				break;
			case Object::Poison:
				mvwaddch(m_field_win, row, col, '6');
				break;
			case Object::Gate:
				mvwaddch(m_field_win, row, col, '7');
				break;
			default:
				break;
			}
		}
	}
}

Facing GameUI::get_input()
{
	int input = wgetch(m_field_win);
	switch (input)
	{
	case KEY_UP:
		return Facing::up;
	case KEY_RIGHT:
		return Facing::right;
	case KEY_DOWN:
		return Facing::down;
	case KEY_LEFT:
		return Facing::left;
	case 'q':
	case 27:
		throw GameEndQuit();
		break;
	}

	return Facing::null;
}

menu_item_t UIUtils::dialogbox(std::string p_text, std::vector<std::string> p_buttons)
{
	// if COLS / 4 < min_width(the width so that all elements would fit) -> width = COLS - 4, else width = COLS / 4
	int width = COLS / 4 < [&p_text, &p_buttons]() -> int
	{
		int min_width = 0;
		for (std::string button : p_buttons)
		{
			min_width += button.length() + 2;
		}
		min_width = min_width > (int)p_text.length() ? min_width : p_text.length();
		return min_width + 10;
	} () ? COLS - 10 : COLS / 4;

	WINDOW *win = newwin(7, width, (LINES - 7) / 2, (COLS - (width)) / 2);
	keypad(win, true);

	box(win, 0, 0);
	mvwprintw(win, 2, (win->_maxx - p_text.length()) / 2, p_text.c_str());
	wrefresh(win);

	menu_item_t selected_item = 0;
	while (true)
	{
		for (std::size_t i = 0; i < p_buttons.size(); ++i)
		{
			// x = (total width of the window / (amount of buttons + 1)) * (current button + 1) - (length of the text of the button / 2)
			mvwprintw(win,
				5,
				(win->_maxx / (p_buttons.size() + 1)) * (i + 1) - (p_buttons[i].length() / 2),
				p_buttons[i].c_str());
		}

		mvwchgat(win, 5, (win->_maxx / (p_buttons.size() + 1)) * (selected_item + 1) - (p_buttons[selected_item].length() / 2), p_buttons[selected_item].length(), A_STANDOUT, 0, NULL);

		switch (wgetch(win))
		{
		case KEY_LEFT:
			selected_item = selected_item != 0 ? selected_item - 1 : p_buttons.size() - 1;
			break;
		case KEY_RIGHT:
			selected_item = selected_item != (int)p_buttons.size() - 1 ? selected_item + 1 : 0;
			break;
			// Enter
		case '\n':
			werase(win);
			wrefresh(win);
			delwin(win);
			return selected_item;
		}
	}

	throw std::logic_error("Out of the infinite while loop");
}

void Game::tick()
{
	const static std::chrono::milliseconds TICK_DURATION(500);
	auto last_tick = std::chrono::high_resolution_clock::now();

	while (true)
	{
		m_player->set_facing(m_ui->get_input());

		// true if the time of the next tick(last tick + tick duration) is in the past
		while ((last_tick + TICK_DURATION) < std::chrono::high_resolution_clock::now())
		{
			update();
			//m_field->place_growth_item();
			//m_field->place_poison_item();
			last_tick += TICK_DURATION;
			flag = 0;
		}


		// sleep for 25 ms
		usleep(25 * 1000);
	}
}

void Game::update()
{
	bool pass = FALSE;
	Point player_head = m_player->get();
	switch (m_field->get(player_head))
	{
	case Object::Growth:
	{
		m_field->set(player_head, Object::player_head);
		m_field->place_growth_item();
		m_player->lengthen();
		Growth_num++;
		Score++;
		break;
	}
	case Object::Poison:
	{
		m_field->set(player_head, Object::player_head);
		m_field->place_poison_item();
		m_player->shorthen();//
		Poison_num++;
		Score--;

		break;
	}
	case Object::Gate:
	{


		Gate_num++;
		pass = TRUE;
		break;
	}
	case Object::wall:
	case Object::player_tail:
	case Object::player_head:
	{
		throw GameEndDeath();
		break;
	}
	default:
		break;
	}

	m_field->update_player(m_player);

	if (pass == TRUE) {
		flag = 1;
		m_player->Gatemove();
		m_field->m_field[Gate[0].y][Gate[0].x] = Object::wall;
		m_field->m_field[Gate[1].y][Gate[1].x] = Object::wall;
		m_field->add_walls();
		pass = FALSE;
	}
	else
		m_player->move(m_field->m_field_size);
	m_ui->update(Score);

	if (m_player->size() < 3) {
		throw GameEndDeath();
	}
}


Game::Game(GameUI *p_ui) : m_ui(p_ui)
{
	m_field = new Field();
	m_ui->set_field(m_field);

	m_player = new Player();
}

Game::~Game()
{
	delete m_field;
	delete m_player;
}

void Game::start()
{
	Score = 0;
	Gate_num = 0;
	Growth_num = 0;
	Poison_num = 0;
	Mission_complete = 0;
	//if(Settings::enable_walls)
	m_field->add_walls();
	m_field->place_growth_item();
	m_field->place_growth_item();
	m_field->place_poison_item();
	m_ui->draw_static_elements();

	while (true)
	{
		try
		{
			tick();
		}
		catch (const GameEndQuit &)
		{
			// TODO: redraw the field when "No" is clicked
			if (UIUtils::dialogbox(std::string("Quit?"), std::vector<std::string> {std::string("No"), std::string("Yes")}) == 1) return;
			m_ui->draw_static_elements();
		}
		catch (const GameEndDeath &)
		{
			UIUtils::dialogbox(std::string("You died"), std::vector<std::string> {std::string("OK")});
			return;
		}
		/*
		catch(const NextStage &)
		{
			UIUtils::dialogbox(std::string("You died"), std::vector<std::string> {std::string("OK")});
			return;
		}*/
	}
}

Point Settings::field_size = { 21, 35 };

int main()
{

	MainMenu main_menu;
	main_menu.show();
	return 0;
}
