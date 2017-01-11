#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime> //pt randomness, pt  srand(time(0));
using namespace std;
bool gameOver;
int width = 60;
int height = 60;
int x, y, fruitX, fruitY, score;
int tailX[300], tailY[300];
int nTail; //length
int minpas;
int kk;
int a[50][50], s[50][50], cs[50][50];
enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
direction dir;
direction prevdir;

void setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	srand(time(0));
	fruitX = rand() % (width - 1);

	fruitY = rand() % (height - 1);
	while (fruitX == 0 || fruitY == 0 || fruitX == x || fruitY == y)
	{
		fruitX = rand() % (width - 1);

		fruitY = rand() % (height - 1);


	}
	score = 0;
}

void harta()
{
	system("cls"); //clear screen
	for (int i = 0; i<width; i++)
		cout << "#";
	cout << endl;
	for (int i = 1; i<height - 1; i++)
	{
		for (int j = 0; j<width; j++)
		{
			if (j == 0 || j == width - 1)
				cout << "#";
			else
				if (i == y&&j == x)
					cout << "O";
				else
					if (i == fruitY&&j == fruitX)
						cout << "F";
					else
					{
						bool printed = false;
						for (int k = 0; k<nTail; k++)
						{
							if (tailX[k] == j&&tailY[k] == i)
							{
								cout << "o";
								printed = true;
							}
						}
						if (!printed)cout << " ";
					}

		}
		cout << endl;
	}


	for (int i = 0; i<width; i++)
		cout << "#";
	cout << endl;

	cout << score;

}


void Input()
{
	char z;   //un fel de cin>>w/a/s/d, doar ca nu mai trebuie enter
	if (_kbhit()) //true if key is pressed, else return 0
	{//_getch->return the key that was pressed
		z = _getch(); //facem substitutie, pt ca daca apelez if(_getch()==' ') de mai multe ori, dupa paima apelare cred ca se pierde valoarea lui _getch() pt ca nu s-a mai apelat nici un _kbhit()
		if (z == 'a'&&dir != RIGHT)
			dir = LEFT; else
			if (z == 'w'&&dir != DOWN)
				dir = UP; else
				if (z == 's'&&dir != UP)
					dir = DOWN; else
					if (z == 'd'&&dir != LEFT)
						dir = RIGHT; else
						if (z == 'x')
							gameOver = true;
		if (z == 'p')

		{
			cout << endl << "press any key to continue";
			while (z == 'p')
			{
				Sleep(5);
				if (_kbhit())
					z = _getch();
			}
		}

	}
}



void Logic()
{
	int ok;


	for (int i = nTail - 1; i >= 1; i--)
	{
		tailX[i] = tailX[i - 1];
		tailY[i] = tailY[i - 1];
	}

	tailX[0] = x;
	tailY[0] = y;

	if (dir == LEFT)
		x--;
	if (dir == RIGHT)
		x++;
	if (dir == UP)
		y--;
	if (dir == DOWN)
		y++;


	if (x >= width - 1 || x <= 0)
		gameOver = true;
	if (y >= height - 1 || y <= 0)
		gameOver = true;

	for (int i = 0; i<nTail; i++)
		if (tailX[i] == x&&tailY[i] == y)
			gameOver = true;

	if (x == fruitX && y == fruitY)
	{
		score++;

		fruitX = rand() % (width - 2);






		fruitY = rand() % (height - 2);



		while (fruitX == 0 || fruitY == 0 || fruitX == x || fruitY == y)
		{
			fruitX = rand() % (width - 1);

			fruitY = rand() % (height - 1);



		} nTail++;


	}
}

