#pragma once
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
#define Max_Length 10
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
int game_times = 0;
int Growth_num = 0;
int Poison_num = 0;
int Gate_num = 0;
int Score = 0;
int Mission_complete = 0;

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
	int mapNumber;
	

};
enum class Object { empty, wall, Immune_Wall, player_head, player_tail, Growth, Poison, Gate };
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
	Object **m_field1;
	Object **m_field2;
	Object **m_field3;
	Object **m_field4;
	Field();
	~Field();
	const Point m_field_size;

	Object get1(Point p_point) const { return m_field1[p_point.y][p_point.x]; }
	void set1(Point p_point, Object p_object) { m_field1[p_point.y][p_point.x] = p_object; }
	Object get2(Point p_point) const { return m_field2[p_point.y][p_point.x]; }
	void set2(Point p_point, Object p_object) { m_field2[p_point.y][p_point.x] = p_object; }
	Object get3(Point p_point) const { return m_field3[p_point.y][p_point.x]; }
	void set3(Point p_point, Object p_object) { m_field3[p_point.y][p_point.x] = p_object; }
	Object get4(Point p_point) const { return m_field4[p_point.y][p_point.x]; }
	void set4(Point p_point, Object p_object) { m_field4[p_point.y][p_point.x] = p_object; }


	void place_growth_item(Object **m_field);
	void place_poison_item(Object **m_field);
	void add_walls1();
	void add_walls2();
	void add_walls3();
	void add_walls4();

	void update_player(Player *p_player, Object **m_field);
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
	int mapNumber;
	GameUI *m_ui;
	Field *m_field;
	Player *m_player;

	void tick();
	void update(Object **m_field);
public:
	Game(GameUI *p_ui);
	~Game();

	void start();
};