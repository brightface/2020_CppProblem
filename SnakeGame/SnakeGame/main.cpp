#include <iostream>
#include <conio.h>
#include <cstdio>
#include <windows.h>

using namespace std;

bool gameover;

const int width = 20;

const int height = 17;

int x, y, fruitX, fruitY, score;
int posionX, posionY;

int tailX[100], tailY[100]; //snake coordinates

int nTail;
//0왼 1오 2위 3아래
int gFlag[2];

struct Gate{
	int y, x;
};

struct Gate w[2];

enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN }; // Controls

eDirecton dir;

void setingGate(int numOfgate) {
	
	gFlag[numOfgate] = rand() % 4;
	//게이트가 왼쪽에 생길때
	if (gFlag[numOfgate] == 0) {
		w[numOfgate].y = rand() % (height-1)+1;
		w[numOfgate].x = 0;
	}
	//게이트가 오른쪽에생길떄
	else if (gFlag[numOfgate] == 1) {
		w[numOfgate].y = rand() % (height-1)+1;
		w[numOfgate].x = width-1;
	}
	//게이트가 위에 생길때
	else if (gFlag[numOfgate] == 2) {
		w[numOfgate].y = 0;
		w[numOfgate].x = rand() % (width-1)+1;
	}
	//게이트가 아래에 생길때
	else {
		w[numOfgate].y =  height-1;
		w[numOfgate].x = rand() % (width-1)+1;
	}
}

void Setup() {
	gameover = false;

	dir = STOP;

	x = width / 2;

	y = height / 2;

	fruitX = rand() % width; //display fruit in a random place

	fruitY = rand() % height; score = 0;
	
	posionX = rand() % width;

	posionY = rand() % height;
	while(fruitX == posionX && fruitY == posionY)
	{
		fruitX = rand() % width;
		fruitY = rand() % height;
	}

}

void Draw() {
	system("cls");
	//맨 윗줄 #로 세팅
	
	for (int i = 0; i < width + 1; i++)
	{
		if (gFlag[0] == 2 || gFlag[1] == 2) {
			if ((w[0].y == 0 && i == w[0].x) || (w[1].y == 0 && i == w[1].x))
			{
				cout << "$";

			}
			else cout << "#";
		}
		else cout << "#";
		
	}
	int flagK = 0;
	////////////////////////////////////////////////
	for (int i = 0; i < height; i++) {
		if (i == height - 1) break; //아랫줄도 넘어감
		for (int j = 0; j < width; j++) {
			if (i == 0) break; //윗줄 세팅했으니까 넘어간다.
			
			/*
			if ((i != w[0].y || i j != w[0].x) && (i != w[1].y || j != w[1].x))
					cout << "#";*/

			//맨 왼쪽줄세팅
			if (j == 0)
				if ((i == w[0].y && w[0].x== j) || (i == w[1].y &&  w[1].x == j))
				{
					cout << "$"; flagK = 1;
					
				}//Gates
				else
					cout << "#";
			//맨 오른쪽줄 세팅
			if(j == width-1 )
				if ((i == w[0].y && w[0].x == j) || (i == w[1].y &&  w[1].x == j))
				{
					cout << "$"; flagK = 1;

				}//Gates
				else
					cout << "#";

			/*if (j == width - 1)
				if ((i == w[0].y && w[0].x==0) || (i == w[1].y &&  w[1].x == 0))*/

			
			//스테이크 출력
			if (i == y && j == x)

				cout << "*"; // snake tale
			//과일출력
			else if (i == fruitY && j == fruitX)
				cout << "%"; // change it to change the fruit
			else if (i == posionY && j == posionX)
				cout << "&";
			
			else {
				
				bool print = false;
				//꼬리만큼 또 출력
				for (int k = 0; k < nTail; k++) {
					//꼬리의 좌표면
					if (tailX[k] == j && tailY[k] == i) {
						//스네이크 출력
						cout << "*"; print = true;

					}

				}
				//끝나면 출력안한다. 띠어쓰기만 출력
				if (!print) cout << " ";

			}
			//맨 오른줄 출력
			/*if (flagK == 1) {
				if (j == width - 1) cout << "#";
			}
			else {
				if (j == width - 1)

					cout << "$";
			}*/
		}

		cout << endl;

	}
	//맨 아랫줄 세팅
	for (int i = 0; i < width + 1; i++)
	{
		if (gFlag[0] == 3 || gFlag[1] == 3) {
			if ((w[0].y == 0 && i == w[0].x) || (w[1].y == 0 && i == w[1].x))
			{
				cout << "$";

			}
		}
		else cout << "#";
	}
	/*for (int i = 0; i < width + 2; i++)

		cout << "#";*/

	cout << endl;

	cout << "Score:" << score << endl;

}

void Input()
{

	if (_kbhit()) {

		switch (_getch()) {

		case 'a':

			dir = LEFT;

			break;

		case 'd':

			dir = RIGHT;

			break;

		case 'w':

			dir = UP;

			break;

		case 's':

			dir = DOWN;

			break;

		case 'x':

			gameover = true;

			break;

		}

	}

}
//시간에 다른 표현 방법. 왜 이렇게 되는진 이해 
void algorithm()
{
	//첫꼬리 이전 꼬리에 0번을 넣는다.
	int prevX = tailX[0]; 
	int prevY = tailY[0]; //한번 전것이다.(이미 아래서 한번 이동 되었으니까)

	int prev2X, prev2Y;
	
	// x,y좌표를 첫꼬리에 넣는다.
	tailX[0] = x; //한번 이동이 되었다.
	tailY[0] = y; //그걸 첫꼬리에 넣었다.

	
	//처음 tailX[1] 은 뭐일까?
	//뒤에서 부터 들어간다. nTail 이 1더 해지면
	for (int i = 1; i < nTail; i++) {
		//두번쨰 전부터 tailX,tailY를 두번쨰 전 prev2X에 넣는다.
		prev2X = tailX[i];
		prev2Y = tailY[i];
		
		//첫번째 전은 다시 출력하기 위해서 테일에 넣는다.
		tailX[i] = prevX;
		tailY[i] = prevY;

		//두번째 전은 첫번쨰 전으로 넣는다.
		prevX = prev2X;
		prevY = prev2Y;

	}

	switch (dir) {

	case LEFT:

			x--;

		break;

	case RIGHT:

		x++;

		break;

	case UP:

		y--;

		break;

	case DOWN:

		y++;

		break;

	default:

		break;

	}
	//벽에 따라 이동
	if (x >= width-1) x = 0; else if (x < 0) x = width - 2;

	if (y >= height) y = 0; else if (y < 0) y = height - 2;
	
	//gFlag 왼 오 위 아래
	//게이트에 따라 이동
	if (gFlag[1] == 0) {
		if (x <= w[1].x && y == w[1].y) {
			x = w[0].x; y = w[0].y;
		}
	}
	else if (gFlag[1] == 1) {
		if(x >= w[1].x && y == w[1].y) x = w[0].x; y = w[0].y;
	}
	else if (gFlag[1] == 2) {
		if (x == w[1].x && y <= w[1].y) x = w[0].x; y = w[0].y;
	}
	else if (gFlag[1] == 3) {
		if (x == w[1].x && y >= w[1].y) x = w[0].x; y = w[0].y;
	}


	/////////////////////////////////////
	/*if (x == w[0].x && y == w[0].y) {
		if (gFlag[1] == 0) { x = w[1].x; y = w[1].y; x++; }
		else if (gFlag[1] == 1) { x = w[1].x; y = w[1].y; x--; }
		else if (gFlag[1] == 2) { x = w[1].x; y = w[1].y;  y--; }
		else if (gFlag[1] == 3) { x = w[1].x; y = w[1].y;  y++; }
		
	}
	if (x == w[1].x && y == w[1].y) {
		if (gFlag[0] == 0) { x = w[0].x; y = w[0].y; x++; }
		else if (gFlag[0] == 1) { x = w[0].x; y = w[0].y; x--; }
		else if (gFlag[0] == 2) { x = w[0].x; y = w[0].y; y--; }
		else if (gFlag[0] == 3) { x = w[0].x; y = w[0].y; y++; }
	}*/


	for (int i = 0; i < nTail; i++)

		if (tailX[i] == x && tailY[i] == y)
			gameover = true;

	if (x == fruitX && y == fruitY) {

		score += 10;

		fruitX = rand() % width;

		fruitY = rand() % height;

		nTail++;

	}
	else if (x == posionX && y == posionY) {

		score -= 10;

		posionX = rand() % width;

		posionY = rand() % height;

		nTail--;

	}

}

int main()
{	
	Setup();
	setingGate(0);
	setingGate(1);
	//게이트가 같으면 다시 게이트를 만든다.
	while (w[0].y == w[1].y && w[0].x == w[1].x) {
		setingGate(1);
	}

	while (!gameover) {
		/*Sleep(500);*/
		Draw();

		Input();

		algorithm();

	}

	return 0;

}