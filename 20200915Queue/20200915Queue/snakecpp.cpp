#define _CRT_NONSTDC_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

using namespace std;

//��½�Ʈ�� : ���������� �ϳ��� ������
//���� �����ڸ��� ��½�Ű�ڴ�. ��� ��Ʈ���� �������� �ȵǴ°ž�.

//getch ���ž�//�Է��̰� ����
//putch
/*
	��¹��۸� ������� �ʰ� ���� �ϳ��� �ֿܼ� �ٷ� ������ִ� �Լ�.

	getch
	�Է� ���۸� ������� �ʰ� �Էµ� Ű�� �ٷ� ������ �����Ѵ�.- �ѱ��� �ȵ�. ���ĺ��̳� Ư������ ����Ұž�. 1����Ʈ��
	stand c �Լ��� �ƴϾ� . _getch ����Ѵ� .�׷��� �׷��� warning ����� ���� �ɼǾ��ž�
	#define _CRT_NONSTDC_NO_WARNINGS
*/

struct Point
{
	int x, y;
};

enum EDir
{
	//Ȯ�� Ű -2���� �־��ִ� Ű��.
	LEFT = 75, //(224 0)
	//0xE0 Ȯ��Ű��� ���������� �����ž�.
	RIGHT = 77,
	UP = 72,
	DOWN = 80
};
bool MoveSnake();
//���� �����̴� ����

//Ŀ���� �ű���ִ� �Լ�
void gotoxy(int x, int y);
void ProcessKey(); //Ű �Է��ϴ��Լ�
void InitStage(int stage);
#define QS 255
#define putchxy(x,y,ch) {gotoxy(x,y); putch(ch);} //�̷��� �ѹ濡 �׷�����.
Point snake[QS];
Point now;
int head, tail;;
int speed;
int Getchcon(int x, int y);
//�ش� ��ġ.
int incTail;
int maxNumber;
int stage;
int multi; //���� �þ ����

EDir dir;




void gotoxy(int x, int y)
{
	COORD pos{ x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//pos�� �̵���������.
}

void ProcessKey()
{
	int ch;

	//Ű�� ���ȴٸ� 1�� ��ȯ�ǰ� �ȴ����� 0�� ��ȯ��
	if (kbhit() == 0) return;

	ch = getch(); //������ �ôµ�
	if (ch == 0xE0 || ch == 0) //224
	{
		//�׷��� Ȯ��Ű��
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
	int prev;//�Ӹ��������� / �Ӹ��׸��� ��� -1 �ε���

	while (true)
	{
		length = head - tail;
		if (length < 0)
			length += QS;
		gotoxy(60, 23);
		printf("�������� : %d", length);

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
		snake[head] = now; //�����ġ�� �� ��ġ�� �־��ָ� �ȴ�.
		//��尡 �� ��ġ�� now
		//now�� �� ��ġ ��� ã�ƺ�����.
		if (incTail == 0)
		{

			//������ ������ 
			tail = tail == QS - 1 ? 0 : tail + 1;
		}
		else incTail--;

		headCh = Getchcon(now.x, now.y);

		putchxy(snake[head].x, snake[head].y, 'S');
		prev = head == 0 ? QS - 1 : head - 1;

		putchxy(snake[prev].x, snake[prev].y, '#');
		//tail�� ������ ������ ��ġ
		prev = tail == 0 ? QS - 1 : tail - 1; //�ٽ� �����ְ�
	
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

	//��
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
	ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), &ch, 1, cur, &dwRead); //cur ��ġ���ִ� ���� 1��¥���� &ch�� �־��ش�.�¶��̾�.
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
			puts("���ӿ���)");

		}

	}
	if (number == maxNumber)
	{
		stage++;
	}
}