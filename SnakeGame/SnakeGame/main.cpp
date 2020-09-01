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
//0�� 1�� 2�� 3�Ʒ�
int gFlag[2];

struct Gate{
	int y, x;
};

struct Gate w[2];

enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN }; // Controls

eDirecton dir;

void setingGate(int numOfgate) {
	
	gFlag[numOfgate] = rand() % 4;
	//����Ʈ�� ���ʿ� ���涧
	if (gFlag[numOfgate] == 0) {
		w[numOfgate].y = rand() % (height-1)+1;
		w[numOfgate].x = 0;
	}
	//����Ʈ�� �����ʿ����拚
	else if (gFlag[numOfgate] == 1) {
		w[numOfgate].y = rand() % (height-1)+1;
		w[numOfgate].x = width-1;
	}
	//����Ʈ�� ���� ���涧
	else if (gFlag[numOfgate] == 2) {
		w[numOfgate].y = 0;
		w[numOfgate].x = rand() % (width-1)+1;
	}
	//����Ʈ�� �Ʒ��� ���涧
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
	//�� ���� #�� ����
	
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
		if (i == height - 1) break; //�Ʒ��ٵ� �Ѿ
		for (int j = 0; j < width; j++) {
			if (i == 0) break; //���� ���������ϱ� �Ѿ��.
			
			/*
			if ((i != w[0].y || i j != w[0].x) && (i != w[1].y || j != w[1].x))
					cout << "#";*/

			//�� �����ټ���
			if (j == 0)
				if ((i == w[0].y && w[0].x== j) || (i == w[1].y &&  w[1].x == j))
				{
					cout << "$"; flagK = 1;
					
				}//Gates
				else
					cout << "#";
			//�� �������� ����
			if(j == width-1 )
				if ((i == w[0].y && w[0].x == j) || (i == w[1].y &&  w[1].x == j))
				{
					cout << "$"; flagK = 1;

				}//Gates
				else
					cout << "#";

			/*if (j == width - 1)
				if ((i == w[0].y && w[0].x==0) || (i == w[1].y &&  w[1].x == 0))*/

			
			//������ũ ���
			if (i == y && j == x)

				cout << "*"; // snake tale
			//�������
			else if (i == fruitY && j == fruitX)
				cout << "%"; // change it to change the fruit
			else if (i == posionY && j == posionX)
				cout << "&";
			
			else {
				
				bool print = false;
				//������ŭ �� ���
				for (int k = 0; k < nTail; k++) {
					//������ ��ǥ��
					if (tailX[k] == j && tailY[k] == i) {
						//������ũ ���
						cout << "*"; print = true;

					}

				}
				//������ ��¾��Ѵ�. ���⸸ ���
				if (!print) cout << " ";

			}
			//�� ������ ���
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
	//�� �Ʒ��� ����
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
//�ð��� �ٸ� ǥ�� ���. �� �̷��� �Ǵ��� ���� 
void algorithm()
{
	//ù���� ���� ������ 0���� �ִ´�.
	int prevX = tailX[0]; 
	int prevY = tailY[0]; //�ѹ� �����̴�.(�̹� �Ʒ��� �ѹ� �̵� �Ǿ����ϱ�)

	int prev2X, prev2Y;
	
	// x,y��ǥ�� ù������ �ִ´�.
	tailX[0] = x; //�ѹ� �̵��� �Ǿ���.
	tailY[0] = y; //�װ� ù������ �־���.

	
	//ó�� tailX[1] �� ���ϱ�?
	//�ڿ��� ���� ����. nTail �� 1�� ������
	for (int i = 1; i < nTail; i++) {
		//�ι��� ������ tailX,tailY�� �ι��� �� prev2X�� �ִ´�.
		prev2X = tailX[i];
		prev2Y = tailY[i];
		
		//ù��° ���� �ٽ� ����ϱ� ���ؼ� ���Ͽ� �ִ´�.
		tailX[i] = prevX;
		tailY[i] = prevY;

		//�ι�° ���� ù���� ������ �ִ´�.
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
	//���� ���� �̵�
	if (x >= width-1) x = 0; else if (x < 0) x = width - 2;

	if (y >= height) y = 0; else if (y < 0) y = height - 2;
	
	//gFlag �� �� �� �Ʒ�
	//����Ʈ�� ���� �̵�
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
	//����Ʈ�� ������ �ٽ� ����Ʈ�� �����.
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