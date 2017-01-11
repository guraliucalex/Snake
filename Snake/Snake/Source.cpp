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

void hartasingle()
{
	if (score<2)
	{
		system("cls");
		for (int i = 0; i<width; i++)
			cout << "#";
		cout << endl;
		for (int i = 1; i<height; i++)
		{
			for (int j = 0; j<width; j++)
			{
				if (j == 0 || j == width - 1)
					cout << "#";
				else if (i == y&&j == x)
					cout << "O";
				else if (i == fruitY&&j == fruitX)
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
	else if ((score >= 2) && (score<4))
	{
		system("cls");
		for (int i = 0; i<width; i++)
			cout << "#";
		cout << endl;
		for (int i = 1; i<height; i++)
		{
			for (int j = 0; j<width; j++)
			{
				if (j == 0 || j == width - 1)
					cout << "#";
				else if (i == y&&j == x)
					cout << "O";
				else if (i == fruitY&&j == fruitX)
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
	else if ((score >= 4) && (score<6))
	{
		system("cls");
		for (int i = 0; i<width; i++)
			cout << "#";
		cout << endl;
		for (int i = 1; i<height; i++)
		{
			for (int j = 0; j<width; j++)
			{
				if (j == 0 || j == width - 1 || ((j == width / 2) && (i>4 && i<height - 4)) || ((i == height / 2) && (j>4 && j<width - 4)))
					cout << "#";
				else if (i == y&&j == x)
					cout << "O";
				else if (i == fruitY&&j == fruitX)
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
	else if ((score >= 6) && (score<8))
	{
		system("cls");
		for (int i = 0; i<width; i++)
			cout << "#";
		cout << endl;
		for (int i = 1; i<height; i++)
		{
			for (int j = 0; j<width; j++)
			{
				if (j == 0 || j == width - 1 || j == width / 3 || i == height / 2)
					cout << "#";
				else if (i == y&&j == x)
					cout << "O";
				else if (i == fruitY&&j == fruitX)
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
	else if (score >= 8)
	{
		system("cls");
		for (int i = 0; i<width; i++)
			cout << "#";
		cout << endl;
		for (int i = 1; i<height; i++)
		{
			for (int j = 0; j<width; j++)
			{
				if ((j == 0) || (j == width - 1) || (j == width / 4 && i>height / 2 - 2) || (j == width / 4 * 2 && i>height / 2 - 2) || (j == width / 4 * 3 && i>height / 2 - 2) || (i == height / 3 - 2 && j>4 && j<width - 4))
					cout << "#";
				else if (i == y&&j == x)
					cout << "O";
				else if (i == fruitY&&j == fruitX)
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
}
int speed()
{
	int viteza = 0;
	string Vit[3] =
	{
		"Easy",
		"Medium",
		"Hard"
	};
	while (true)
	{
		system("cls");
		for (int v = 0; v <= 2; v++)
		{
			if (v == viteza)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << Vit[v] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << Vit[v] << endl;
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				viteza = viteza - 1;
				if (viteza == -1)
				{
					viteza = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				viteza = viteza + 1;
				if (viteza == 3)
				{
					viteza = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (viteza)
				{
				case 0:
				{
					return 1000;
				}
				case 1:
				{
					return 2000;
				}
				case 2:
				{
					return 3000;
				}
				}
			}
			Sleep(1000);
		}
	}
}
int mode()
{
	int modul = 0;
	string Mode[3] =
	{
		"Single player",
		"Ai Snake",
		"Player vs computer"
	};
	while (true)
	{
		system("cls");
		for (int m = 0; m <= 2; m++)
		{
			if (m == modul)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << Mode[m] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << Mode[m] << endl;
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				modul = modul - 1;
				if (modul == -1)
				{
					modul = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				modul = modul + 1;
				if (modul == 3)
				{
					modul = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (modul)
				{
				case 0:
				{
					return 100;
				}
				case 1:
				{
					return 200;
				}
				case 2:
				{
					return 300;
				}
				}
			}
			Sleep(1000);
		}
	}
}
