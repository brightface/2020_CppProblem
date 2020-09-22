#define _CRT_NONSTDC_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>


//putch
/*
   출력 버퍼를 사용하지 않고 문자 하나를 콘솔에 바로 출력해주는 함수.

   getch
   입력 버퍼를 사용하지 않고 입력된 키를 바로 변수에 저장한다.
*/

struct Point
{
    int x, y;
};

enum EDir
{
    LEFT = 75, //224 0
    RIGHT = 77,
    UP = 72,
    DOWN = 80,
};

#define QS 255
#define putchxy(x, y, ch) { gotoxy(x,y); putch(ch);}

Point snake[QS];
Point now;
int head, tail;
int speed;
int incTail;
int maxNumber;
int stage;
int multi;
int life=3;

int Getchcon(int x, int y);

EDir dir;

bool MoveSnake();
void gotoxy(int x, int y);
void ProcessKey();
void InitStage(int stage);
void WaitAnyKey();

int main()
{
    CONSOLE_CURSOR_INFO info{ 1, false };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);



    int x = 10, y = 10;
    int number,ch;
    while (true)
    {
        InitStage(stage);
        gotoxy(0, 23); printf("스테이지 : %d", stage + 1);
        gotoxy(20, 23); printf("남은 뱀 : %d", life);
        for (number = 0; number < maxNumber; number++)
        {
            gotoxy(40, 23); printf("남은 먹이 : %d", maxNumber - number);
            gotoxy(60, 23); printf("꼬리 길이 : 2");
            do
            {
                x = rand() % 80;
                y = rand() % 22;

            } while (Getchcon(x, y) != ' ');
            gotoxy(x, y);
            printf("%d", rand() % 9 + 1);

            if (number == 0) //확장키라면
            {
                ch = getch();
                if (ch == 0xE0)
                    getch();
                else 
                {
                    if (tolower(ch) == 'p') //prev
                    {
                        stage = stage == 0 ? 2 : stage - 1;
                        break;
                    }
                    else if (tolower(ch) == 'n') //next
                    {
                        stage = stage == 2 ? 0 : stage + 1;
                    }

                }
            }

            if (MoveSnake() == true)
            {
                if (--life == 0)
                {
                    gotoxy(36, 10);
                    puts("게임오버");
                    gotoxy(0, 30);
                    return 0;
                }
                //정신차릴시간을 주자.
                Sleep(1500);
                break;//포문 탈출하는 break야.
               
            }
        }
        if (number == maxNumber)
        {
            gotoxy(21, 10);
            puts("아무키나 누르면 다음 스테이지로 이동");
            WaitAnyKey();
            stage++;
        }
    }


    return 0;
}

int Getchcon(int x, int y)
{
    COORD cur{ x, y };
    TCHAR ch;
    DWORD dwRead;
    ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), &ch, 1, cur, &dwRead);
    return ch;
}

bool MoveSnake()
{
    int headCh;
    int prev;
    int length;

    while (true)
    {
        length = head - tail;
        if (length < 0)
            length += QS;
        gotoxy(60, 23);
        printf("꼬리 길이 : %d", length);
        gotoxy(60, 24);
        printf("늘어날 꼬리 길이 : %2d", incTail);

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
        snake[head] = now;

        if (incTail == 0)
            tail = tail == QS - 1 ? 0 : tail + 1;
        else
            incTail--;

        headCh = Getchcon(now.x, now.y);

        putchxy(snake[head].x, snake[head].y, 'S');
        prev = head == 0 ? QS - 1 : head - 1;

        putchxy(snake[prev].x, snake[prev].y, '#');
        prev = tail == 0 ? QS - 1 : tail - 1;

        putchxy(snake[prev].x, snake[prev].y, ' ');

        if (headCh != ' ')
            break;

        Sleep(speed);
    }

    if (headCh == '#' || headCh == 'M')
        return true;

    incTail += (headCh - '0') * 3;

    return false;
}

void gotoxy(int x, int y)
{
    COORD pos{ x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ProcessKey()
{
    int ch;

    if (kbhit() == 0) return;

    ch = getch();
    if (ch == 0xE0 || ch == 0)
    {
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
    else
    {
        switch (tolower(ch))
        {
        case VK_ESCAPE:
            exit(0);
        }
    }
}

void InitStage(int stage)
{
    system("cls");
    snake[0].x = 5; snake[0].y = 5;
    snake[1].x = 6; snake[1].y = 5;
    snake[2].x = 7; snake[2].y = 5;
    gotoxy(5, 5);
    
    //이게 시작
    puts("##S");

    head = 2;
    tail = 0;
    now.x = 7;
    now.y = 5;
    dir = RIGHT;
    speed = 150;
    incTail = 0;
    for (int i = 0; i < 80; i++)
    {
        putchxy(i, 0, 'M');
        putchxy(i, 22, 'M');
    }

    for (int i = 0; i < 23; i++)
    {
        putchxy(0, i, 'M');
        putchxy(79, i, 'M');
    }

    switch (stage)
    {
    case 0:
    {
        maxNumber = 3; speed = 150; multi = 3;
        for (int i = 30; i <= 50; i++)
            putchxy(i, 11, 'M');
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

void WaitAnyKey()
{
    int ch;
    ch = getch();
    //스트림버퍼르 안쓰는거지 버퍼를 쓰긴써.
    if (ch == 0xE0 || ch == 0)
        getch();
}
