#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime> //pt randomness, pt  srand(time(0));
using namespace std;
bool gameOver;
const int width=50;
const int height=20;
int x, y;
int x1, y1, fruitX, fruitY, score;
int tailX1[100], tailY1[100];
int tailX[100], tailY[100];
int nTail1,nTail; //length
enum direction {STOP=0,LEFT,RIGHT,UP,DOWN};
direction dir;
direction dir1;
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




void setup_single_vs_ai()
{
	gameOver = false;
	dir1 = STOP;
	x1 = width / 2;
	y1 = height / 2;
	srand(time(0));
	fruitX = rand() % width - 1;
	if (fruitX == 0) fruitX++;

	fruitY = rand() % height - 1;
	if (fruitY == 0)fruitY++;
	score = 0;

	dir = STOP;
	x = width / 2 + 5;
	y = height / 2 + 5;


}

void harta_single_vs_ai()
{
	system("cls"); //clear screen
	for (int i = 0; i<width; i++)
		cout << "*";
	cout << endl;
	for (int i = 1; i<height - 1; i++)
	{
		for (int j = 0; j<width; j++)
		{
			if (j == 0 || j == width - 1)
				cout << "*";
			else
				if (i == y&&j == x)
					cout << "C"; else
					if (i == y1&&j == x1)
						cout << "O"; else


						if (i == fruitY&&j == fruitX)
							cout << "F";
						else
						{
							bool printed = false;
							for (int k = 0; k<nTail1; k++)
							{
								if (tailX1[k] == j&&tailY1[k] == i)
								{
									cout << "o";
									printed = true;
								}
							}
							for (int k = 0; k<nTail; k++)
							{
								if (tailX[k] == j&&tailY[k] == i)
								{
									cout << "c";
									printed = true;
								}
							}

							if (!printed)cout << " ";
						}

		}
		cout << endl;
	}


	for (int i = 0; i<width; i++)
		cout << "*";
	cout << endl;

	cout << score;

}


void Input_single_vs_ai()
{
	char z;   //un fel de cin>>w/a/s/d, doar ca nu mai trebuie enter
	if (_kbhit()) //true if key is pressed, else return 0
	{
		//_getch->return the key that was pressed
		z = _getch(); //facem substitutie, pt ca daca apelez if(_getch()==' ') de mai multe ori, dupa paima apelare cred ca se pierde valoarea lui _getch() pt ca nu s-a mai apelat nici un _kbhit()
		if (z == 'a'&&dir1 != RIGHT)
			dir1 = LEFT;
		else if (z == 'w'&&dir1 != DOWN)
			dir1 = UP;
		else if (z == 's'&&dir1 != UP)
			dir1 = DOWN;
		else if (z == 'd'&&dir1 != LEFT)
			dir1 = RIGHT;
		else if (z == 'x')
			gameOver = true;

	}




}


void Logic_single_vs_ai()
{
	/*int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X,prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for(int i=1;i<nTail;i++)
	{
	prev2X=tailX[i];
	prev2Y=tailY[i];
	tailX[i]=prevX;
	tailY[i]=prevY;
	prevX=prev2X;
	prevY=prev2Y;
	}
	*/

	for (int i = nTail1 - 1; i >= 1; i--)
	{
		tailX1[i] = tailX1[i - 1];
		tailY1[i] = tailY1[i - 1];
	}

	tailX1[0] = x1;
	tailY1[0] = y1;

	if (dir1 == LEFT)
		x1--;
	if (dir1 == RIGHT)
		x1++;
	if (dir1 == UP)
		y1--;
	if (dir1 == DOWN)
		y1++;


	if (x1 >= width - 1 || x1 <= 0)
	{
		gameOver = true; cout << endl << "YOU LOST";
	}
	if (y1 >= height - 1 || y1 <= 0)
	{
		gameOver = true; cout << endl << "YOU LOST";
	}

	for (int i = 0; i<nTail1; i++)
		if (tailX1[i] == x1&&tailY1[i] == y1)
		{
			gameOver = true; cout << endl << "YOU LOST";
		}
	for (int i = 0; i<nTail; i++)
		if (tailX[i] == x1&&tailY[i] == y1)
		{
			gameOver = true; cout << endl << "YOU LOST";
		}
	if (x1 == fruitX && y1 == fruitY)
	{
		score++;

		fruitX = rand() % (width - 1);
		if (fruitX == 0) fruitX++;

		fruitY = rand() % (height - 1);
		if (fruitY == 0)fruitY++;

		nTail1++;

	}


}


void Logic_ai()
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
	{
		gameOver = true; cout << endl << "YOU WON";
	}
	if (y >= height - 1 || y <= 0)
	{
		gameOver = true; cout << endl << "YOU WON";
	}

	for (int i = 0; i<nTail; i++)
		if (tailX[i] == x&&tailY[i] == y)
		{
			gameOver = true; cout << endl << "YOU WON";
		}

	for (int i = 0; i<nTail1; i++)
		if (tailX1[i] == x&&tailY1[i] == y)
		{
			gameOver = true; cout << endl << "YOU WON";
		}


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

int main()
{

	setup_single_vs_ai();
	while (!gameOver)
	{
		harta_single_vs_ai();
		Input_AI_single_vs_ai();
		Input_single_vs_ai();

		Logic_ai();
		Logic_single_vs_ai();
		Sleep(100);

	}

	return 0;
}