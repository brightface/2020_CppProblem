#define _CRT_NONSTDC_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

using namespace std;

//출력스트림 : 모은다음에 하나씩 찎느다
//문자 들어오자마자 출력시키겠다. 출력 스트림이 있을때는 안되는거야.

//getch 쓸거야//입렵이고 ㅋㅋ
//putch
/*
	출력버퍼를 사용하지 않고 문자 하나를 콘솔에 바로 출력해주는 함수.

	getch
	입력 버퍼를 사용하지 않고 입력된 키를 바로 변수에 저장한다.- 한글잘 안돼. 알파벳이나 특수문자 사용할거야. 1바이트라서
	stand c 함수가 아니야 . _getch 써야한다 .그러면 그래서 warning 띄우지 말자 옵션쓸거야
	#define _CRT_NONSTDC_NO_WARNINGS
*/

struct Point
{
	int x, y;
};

enum EDir
{
	//확장 키 -2개를 넣어주는 키다.
	LEFT = 75, //(224 0)
	//0xE0 확장키라면 정상적으로 돌릴거야.
	RIGHT = 77,
	UP = 72,
	DOWN = 80
};
bool MoveSnake();
//뱀이 움직이는 로직

//커서를 옮길수있는 함수
void gotoxy(int x, int y);
void ProcessKey(); //키 입력하는함수
void InitStage(int stage);
#define QS 255
#define putchxy(x,y,ch) {gotoxy(x,y); putch(ch);} //이렇게 한방에 그려주자.
Point snake[QS];
Point now;
int head, tail;;
int speed;
int Getchcon(int x, int y);
//해당 위치.
int incTail;
int maxNumber;
int stage;
int multi; //꼬리 늘어날 개수

EDir dir;




void gotoxy(int x, int y)
{
	COORD pos{ x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//pos로 이동시켜주자.
}

void ProcessKey()
{
	int ch;

	//키가 눌렸다면 1이 반환되고 안눌리면 0이 반환돼
	if (kbhit() == 0) return;

	ch = getch(); //꺼내서 봤는데
	if (ch == 0xE0 || ch == 0) //224
	{
		//그러면 확장키야
		ch = getch();
		switch (ch)
		{
		case LEFT:
			if (dir != RIGHT)
				dir = LEFT;
			break;
		case RIGHT:
			if (dir != LEFT)
				dir = RIGHT;
			break;
		case UP:
			if (dir != DOWN)
				dir = UP;
			break;
		case DOWN:
			if (dir != UP)
				dir = DOWN;
			break;

		}
	}
}

bool MoveSnake()
{
	int length;
	int headCh;
	int prev;//머리이전저장 / 머리그리고 헤드 -1 인덱스

	while (true)
	{
		length = head - tail;
		if (length < 0)
			length += QS;
		gotoxy(60, 23);
		printf("꼬리길이 : %d", length);

		ProcessKey();
		switch (dir)
		{
		case LEFT:
			now.x--;
			break;
		case RIGHT:
			now.x++;
			break;
		case UP:
			now.y--;
			break;
		case DOWN:
			now.y++;
			break;

		}
		head = head == QS - 1 ? 0 : head + 1;
		snake[head] = now; //헤드위치에 갈 위치를 넣어주면 된다.
		//헤드가 갈 위치는 now
		//now가 갈 위치 어떻게 찾아보느냐.
		if (incTail == 0)
		{

			//마지막 테일이 
			tail = tail == QS - 1 ? 0 : tail + 1;
		}
		else incTail--;

		headCh = Getchcon(now.x, now.y);

		putchxy(snake[head].x, snake[head].y, 'S');
		prev = head == 0 ? QS - 1 : head - 1;

		putchxy(snake[prev].x, snake[prev].y, '#');
		//tail은 꼬리의 마지막 위치
		prev = tail == 0 ? QS - 1 : tail - 1; //다시 돌려주고
	
		putchxy(snake[prev].x, snake[prev].y, ' ');

		if (headCh != ' ')
			break;
		Sleep(speed);
	}
	if (headCh == '#' || headCh == 'M')
		return true;

	incTail += headCh - '0';

	return false;
}
void InitStage(int stage)
{
	snake[0].x = 5; snake[0].y = 5;
	snake[1].x = 6; snake[1].y = 5;
	snake[2].x = 7; snake[2].y = 5;
	gotoxy(5, 5); puts("##S");

	head = 2;
	tail = 0;
	now.x = 7;
	now.y = 5;
	dir = RIGHT;
	speed = 100;

	//맵
	for (int i = 0; i < 80; i++)
	{
		putchxy(i, 0, 'M');
		putchxy(i, 22, 'M');

	}
	for (int i = 0; i < 23; i++)
	{
		putchxy(0, i,'M');
		putchxy(79, i, 'M');
	}

	switch (stage)
	{
		case 0:
		{
			maxNumber = 3; speed = 150; multi = 3;
			break;
		}
		case 1:
		{
			maxNumber = 5; speed = 100; multi = 5;
			break;
		}
		case 2:
		{
			maxNumber = 10; speed = 80; multi = 7;
			break;
		}
	}
}

int Getchcon(int x, int y)
{
	COORD cur{ x,y };
	TCHAR ch;
	DWORD dwRead;
	ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), &ch, 1, cur, &dwRead); //cur 위치에있는 문자 1개짜리를 &ch에 넣어준다.는뜻이야.
	return ch;
	
}

int main()
{
	CONSOLE_CURSOR_INFO info{ 1, false };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	
	int x=10 , y=10;
	int number;
	while (true)
	{
		
		for (number = 0; number < maxNumber; number++)
		{
			
			do
			{
				InitStage(number);
				x = rand() % 80;
				y = rand() % 22;
			} while (Getchcon(x, y) != ' ');
			gotoxy(10, 10);
			printf("%d", rand() % 9 + 1);

			MoveSnake();
		}

		if (MoveSnake() == true)
		{
			gotoxy(36, 10);
			puts("게임오버)");

		}

	}
	if (number == maxNumber)
	{
		stage++;
	}
}