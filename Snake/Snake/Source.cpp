#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;
bool gameOver;
int width;
int height;
int x, y;
bool SpawnedBonus, SpawnedCoada, SpawnedSlow, SpawnedSleep;
int x1, y1, fruitX, fruitY, score, bonusX, bonusY, coadaX, coadaY, slowX, slowY, SLOW;
int tailX1[100], tailY1[100];
int  tailX[100], tailY[100];
int nTail1, nTail;
enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
direction dir;
direction dir1;
direction prevdir;
int menu = 0;
int mod = 0;
int vitezaaleasa = 0;
int viti = 0;
int ales = 0;
int simplu[10], vs[10];
char numesg[10][10], numevs[10][10];


void highScoresingle()
{
	int i, j, n;
	i = 0;
	n = 0;
	int aux = 0;
	ifstream fin("highscore_single.txt");
	for (i = 0; i<10; i++)
		fin >> simplu[i];
	fin.close();
	if (score > simplu[9])
	{
		simplu[9] = score;
		cout << "\t Enter your name: " << endl;
		cout << "Your name: ";
		cin.get();
		cin.getline(numesg[10], 10);
		cout << endl;
		cout << endl << endl;
		for (i = 0; i<10; i++)
			for (j = i; j<9; j++)
				if (simplu[i]<simplu[j])
				{
					aux = simplu[i];
					simplu[i] = simplu[j];
					simplu[j] = aux;
				}
	}
	for (int i = 0; i<10; i++)
		cout << i + 1 << '.' << "  " << simplu[i] << "       " << numesg[i] << endl;






	ofstream fout("highscore_single.txt");
	for (i = 0; i<10; i++)
		fout << simplu[i] << "    " << numesg[i] << endl;
	fout.close();



}
void highscorevs()
{
	int i, j, n;
	i = 0;
	n = 0;
	int aux = 0;
	ifstream fin("highscore_vs.txt");
	for (i = 0; i<10; i++)
		fin >> vs[i];
	fin.close();
	if (score > vs[9])
	{
		vs[9] = score;
		cout << "\t Enter your name: " << endl;
		cout << "Your name: ";
		cin.get();
		cin.getline(numevs[10], 10);
		cout << endl;
		cout << endl << endl;
		for (i = 0; i<10; i++)
			for (j = i; j<9; j++)
				if (vs[i]<vs[j])
				{
					aux = vs[i];
					vs[i] = vs[j];
					vs[j] = aux;
				}
	}
	for (int i = 0; i<10; i++)
		cout << i + 1 << '.' << "  " << vs[i] << "       " << numevs[i] << endl;






	ofstream fout("highscore_vs.txt");
	for (i = 0; i<10; i++)
		fout << vs[i] << "    " << numevs[i] << endl;
	fout.close();


}
void printvs()
{
	int i, j;
	cout << "HIGHSCORES VS:" << endl << endl;
	ifstream fin("highscore_VS.txt");
	for (i = 0; i<10; i++)
	{
		fin >> vs[i];
		cout << i + 1 << ". " << vs[i] << endl;
	}

	fin.close();
}
void printall()
{
	int i, j;
	cout << "HIGHSCORES VS:" << endl << endl;
	ifstream fin1("highscore_VS.txt");
	for (i = 0; i<10; i++)
	{
		fin1 >> vs[i];
		cout << i + 1 << ". " << vs[i] << endl;
	}

	fin1.close();
	cout << "HIGHSCORES SINGLE:" << endl << endl;
	ifstream fin2("highscore_single.txt");
	for (i = 0; i<10; i++)
	{
		fin2 >> simplu[i];
		cout << i + 1 << ". " << simplu[i] << endl;
	}

	fin2.close();
}


void printsingle()
{
	int i, j;
	cout << "HIGHSCORES SINGLE:" << endl << endl;
	ifstream fin("highscore_single.txt");
	for (i = 0; i<10; i++)
	{
		fin >> simplu[i];
		cout << i + 1 << ". " << simplu[i] << endl;
	}

	fin.close();
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
	bonusX = 0;
	bonusY = 0;
	SpawnedBonus = false;
	SpawnedCoada == false;
	SpawnedSleep = false;
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
			else if (i == y&&j == x)
				cout << "C";
			else if (i == y1&&j == x1)
				cout << "O";
			else


				if (i == fruitY&&j == fruitX)
					cout << "F";
				else if (i == bonusY&&j == bonusX)
					cout << "B";
				else if (i == coadaY&&j == coadaX)
					cout << "T";
				else if (i == slowY&&j == slowX)
					cout << "S";

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

void power_up_bonus_single()
{
	if (score % 5 == 0 && score>1 && SpawnedBonus == false)
	{
		bonusX = 1 + (rand() % (width - 3));

		bonusY = 1 + (rand() % (height - 3));
		SpawnedBonus = true;
	}


	if (x == bonusX&&y == bonusY)
	{
		score = score + 11; bonusX = 0; SpawnedBonus = false;
	}

}

void power_up_bonus()
{
	if (score % 5 == 0 && score>1 && SpawnedBonus == false)
	{
		bonusX = 1 + (rand() % (width - 3));

		bonusY = 1 + (rand() % (height - 3));
		SpawnedBonus = true;
	}


	if (x1 == bonusX&&y1 == bonusY)
	{
		score = score + 11;
		bonusX = 0;
		SpawnedBonus = false;
	}

}


void power_up_coada()
{
	if (score % 4 == 0 && score>1 && SpawnedCoada == false)
	{
		coadaX = 1 + (rand() % (width - 3));

		coadaY = 1 + (rand() % (height - 3));
		SpawnedCoada = true;
	}


	if (x1 == coadaX&&y1 == coadaY)
	{
		nTail1 = nTail1 - 1;
		score++;
		coadaX = 0;
		SpawnedCoada = false;
	}

}
void power_up_coada_single()
{
	if (score % 4 == 0 && score>1 && SpawnedCoada == false)
	{
		coadaX = 1 + (rand() % (width - 3));

		coadaY = 1 + (rand() % (height - 3));
		SpawnedCoada = true;
	}


	if (x == coadaX&&y == coadaY)
	{
		nTail1 = nTail1 - 1;
		score++;
		coadaX = 0;
		SpawnedCoada = false;
	}

}
void power_up_slow_single()
{
	if (score % 2 == 0 && score>1 && SpawnedSlow == false)
	{
		slowX = 1 + (rand() % (width - 3));

		slowY = 1 + (rand() % (height - 3));
		SpawnedSlow = true;
	}


	if (x == slowX&&y == slowY)
	{
		slowX = 0;
		score++;
		SpawnedSlow = false;
		slowX = 0;
		SLOW = 10;
	}

}

void power_up_slow()
{
	if (score % 2 == 0 && score>1 && SpawnedSlow == false)
	{
		slowX = 1 + (rand() % (width - 3));

		slowY = 1 + (rand() % (height - 3));
		SpawnedSlow = true;
	}


	if (x1 == slowX&&y1 == slowY)
	{
		slowX = 0;
		score++;
		SpawnedSlow = false;
		slowX = 0;
		SLOW = 10;
	}

}
void Logic_single_vs_ai()
{
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
		gameOver = true;
		cout << endl << "YOU LOST";
	}
	if (y1 >= height - 1 || y1 <= 0)
	{
		gameOver = true;
		cout << endl << "YOU LOST";
	}

	for (int i = 0; i<nTail1; i++)
		if (tailX1[i] == x1&&tailY1[i] == y1)
		{
			gameOver = true;
			cout << endl << "YOU LOST";
		}
	for (int i = 0; i<nTail; i++)
		if (tailX[i] == x1&&tailY[i] == y1)
		{
			gameOver = true;
			cout << endl << "YOU LOST";
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
void Input_AI_single_vs_ai()
{
	int k, ok, q, z;

	if (y>fruitY - 1 && x<fruitX)
	{
		if (y >= fruitY&&x>fruitX&&x == width - 2)
		{
			dir = DOWN;
		}
		else if (y>fruitY)
			dir = UP;
		else if (x<fruitX)
			dir = RIGHT;
		else if (y<fruitY)
			dir = DOWN;
		else if (x>fruitX)
			dir = LEFT;
	}
	else if (y>fruitY - 1 && x>fruitX)
	{
		if (y >= fruitY&&x>fruitX&&x == width - 2)
		{
			dir = DOWN;
		}
		else if (y<fruitY)
			dir = DOWN;
		else if (x>fruitX)
			dir = LEFT;
		else if (y>fruitY)
			dir = UP;
		else if (x<fruitX)
			dir = RIGHT;


	}
	else if (y<fruitY&&x<fruitX - 1)
	{
		if (y >= fruitY&&x>fruitX&&x == width - 2)
		{
			dir = DOWN;
		}
		else if (x<fruitX)
			dir = RIGHT;
		else if (y<fruitY)
			dir = DOWN;
		else if (x>fruitX)
			dir = LEFT;
		else if (y>fruitY)
			dir = UP;


	}
	else if (y<fruitY&&x>fruitX - 1)
	{
		if (y >= fruitY&&x>fruitX&&x == width - 2)
		{
			dir = DOWN;
		}
		else if (y<fruitY)
			dir = DOWN;
		else if (x>fruitX)
			dir = LEFT;
		else

			if (y>fruitY)
				dir = UP;
			else if (x<fruitX)
				dir = RIGHT;

	}



	prevdir = dir;

	k = 0;
	ok = 0;
	while (ok == 0)
	{
		ok = 1;
		for (q = 0; q<nTail; q++)
			if ((tailX[q] == x + 1 && tailY[q] == y&&dir == RIGHT) || (tailX[q] == x - 1 && tailY[q] == y&&dir == LEFT)
				|| (tailX[q] == x&&tailY[q] == y + 1 && dir == DOWN) || (tailX[q] == x&&tailY[q] == y - 1 && dir == UP) ||
				(x + 1 == width - 1 && dir == RIGHT) || (x == 1 && dir == LEFT) || (y == 1 && dir == UP) || (y == height - 2 && dir == DOWN))
				ok = 0;
		for (q = 0; q<nTail1; q++)
			if ((tailX1[q] == x + 1 && tailY1[q] == y&&dir == RIGHT) || (tailX1[q] == x - 1 && tailY1[q] == y&&dir == LEFT)
				|| (tailX1[q] == x&&tailY1[q] == y + 1 && dir == DOWN) || (tailX1[q] == x&&tailY1[q] == y - 1 && dir == UP)
				)
				ok = 0;
		if ((x + 1 == x1&&dir == RIGHT&&y == y1) || (x - 1 == x1&&dir == LEFT&&y == y1) || (y - 1 == y1&&dir == UP&&x == x1) || (y + 1 == y1&&dir == DOWN&&x == x1))
			ok = 0;

		if (ok == 0)
		{
			if (k % 4 == 0)
				dir = UP;
			if (k % 4 == 1)
				dir = RIGHT;
			if (k % 4 == 2)
				dir = DOWN;
			if (k % 4 == 3)
				dir = LEFT;
		}

		k++;
		if (k == 25)gameOver = true;
	}

	int ii;
	for (q = 0; q<nTail; q++)
		if (prevdir == UP && ((tailX[q] == x&&tailY[q] == y - 1)))
		{
			if (dir == RIGHT)
			{
				for (ii = 0; ii<width; ii++)
					for (q = 0; q<nTail; q++)
					{
						if (x + ii == tailX[q] && y == tailY[q])
							dir = LEFT;
					}
			}
			else

				if (dir == LEFT)
					for (ii = 0; ii<width; ii++)
						for (q = 0; q<nTail; q++)
						{
							if (x - ii == tailX[q] && y == tailY[q])
								dir = RIGHT;
						}

		}
	for (q = 0; q<nTail; q++)
		if (prevdir == DOWN && ((tailX[q] == x&&tailY[q] == y + 1)))
		{
			if (dir == RIGHT)
			{
				for (ii = 0; ii<width; ii++)
					for (q = 0; q<nTail; q++)
					{
						if (x + ii == tailX[q] && y == tailY[q])
							dir = LEFT;
					}
			}
			else

				if (dir == LEFT)
					for (ii = 0; ii<width; ii++)
						for (q = 0; q<nTail; q++)
						{
							if (x - ii == tailX[q] && y == tailY[q])
								dir = RIGHT;
						}

		}


	for (q = 0; q<nTail; q++)
		if (prevdir == RIGHT && ((tailX[q] == x + 1 && tailY[q] == y)))
		{
			if (dir == DOWN)
			{
				for (ii = 0; ii<height; ii++)
					for (q = 0; q<nTail; q++)
					{
						if (y + ii == tailY[q] && x == tailX[q])
							dir = UP;
					}
			}
			else

				if (dir == UP)
					for (ii = 0; ii<height; ii++)
						for (q = 0; q<nTail; q++)
						{
							if (y - ii == tailY[q] && x == tailX[q])
								dir = DOWN;
						}

		}
	for (q = 0; q<nTail; q++)
		if (prevdir == LEFT && ((tailX[q] == x - 1 && tailY[q])))
		{
			if (dir == UP)
			{
				for (ii = 0; ii<height; ii++)
					for (q = 0; q<nTail; q++)
					{
						if (y - ii == tailY[q] && x == tailX[q])
							dir = DOWN;
					}
			}
			else if (dir == DOWN)
			{
				for (ii = 0; ii<height; ii++)
					for (q = 0; q<nTail; q++)
					{
						if (y + ii == tailY[q] && x == tailX[q])
							dir = UP;
					}



			}

		}
}
void setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	srand(time(0));
	fruitX = rand() % (width - 1);
	srand(time(0));
	fruitY = rand() % (height - 1);
	while (fruitX == 0 || fruitY == 0 || fruitX == x || fruitY == y)
	{
		srand(time(0));
		fruitX = rand() % (width - 1);
		srand(time(0));
		fruitY = rand() % (height - 1);


	}
	bonusX = 0;
	bonusY = 0;
	SpawnedBonus = false;
	SpawnedCoada == false;
	SpawnedSleep = false;
	score = 0;
}


void harta()
{
	if (score<2)

	{
		system("cls"); //clear screen
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
				else if (i == bonusY&&j == bonusX)
					cout << "B";
				else if (i == coadaY&&j == coadaX)
					cout << "T";
				else if (i == slowY&&j == slowX)
					cout << "S";
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

		system("cls"); //clear screen
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
				else if (i == bonusY&&j == bonusX)
					cout << "B";
				else if (i == coadaY&&j == coadaX)
					cout << "T";
				else if (i == slowY&&j == slowX)
					cout << "S";
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

		system("cls"); //clear screen
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
				else if (i == bonusY&&j == bonusX)
					cout << "B";
				else if (i == coadaY&&j == coadaX)
					cout << "T";
				else if (i == slowY&&j == slowX)
					cout << "S";
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

		system("cls"); //clear screen
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
				else if (i == bonusY&&j == bonusX)
					cout << "B";
				else if (i == coadaY&&j == coadaX)
					cout << "T";
				else if (i == slowY&&j == slowX)
					cout << "S";
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
		system("cls"); //clear screen
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
				else if (i == bonusY&&j == bonusX)
					cout << "B";
				else if (i == coadaY&&j == coadaX)
					cout << "T";
				else if (i == slowY&&j == slowX)
					cout << "S";
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
void harta2()
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
							cout << "F"; else
							if (i == bonusY&&j == bonusX)
								cout << "B"; else
								if (i == coadaY&&j == coadaX)
									cout << "T"; else
									if (i == slowY&&j == slowX)
										cout << "S";

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


void Input()
{
	char z;
	if (_kbhit())
	{
		z = _getch();
		if (z == 'a'&&dir != RIGHT)
			dir = LEFT;
		else if (z == 'w'&&dir != DOWN)
			dir = UP;
		else if (z == 's'&&dir != UP)
			dir = DOWN;
		else if (z == 'd'&&dir != LEFT)
			dir = RIGHT;
		else if (z == 'x')
			gameOver = true;

	}

}
void Input2()
{
	char z;
	if (_kbhit())
	{
		z = _getch();
		if (z == 'a'&&dir != RIGHT)
			dir = LEFT;
		else if (z == 'w'&&dir != DOWN)
			dir = UP;
		else if (z == 's'&&dir != UP)
			dir = DOWN;
		else if (z == 'd'&&dir != LEFT)
			dir = RIGHT;
		else if (z == 'x')
			gameOver = true;

	}
}




void Logic()
{


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

	if (score<2)
	{
		if (x >= width) x = 0;
		else if (x < 0) x = width - 1;
		if (y >= height) y = 0;
		else if (y < 0) y = height - 1;
		for (int i = 0; i<nTail; i++)
			if (tailX[i] == x&&tailY[i] == y)
				gameOver = true;
	}
	else if ((score >= 2) && (score<4))
	{
		if (x >= width - 1 || x <= 0)
			gameOver = true;
		if (y >= height || y <= 0)
			gameOver = true;
		for (int i = 0; i<nTail; i++)
			if (tailX[i] == x&&tailY[i] == y)
				gameOver = true;


	}
	else if ((score >= 4) && (score<6))
	{
		if (x >= width) x = 0;
		else if (x < 0) x = width - 1;
		if (y >= height) y = 0;
		else if (y < 0) y = height - 1;
		if (((x == width / 2) && (y>4 && y<height - 4)) || ((y == height / 2) && (x>4 && x<width - 4)))
			gameOver = true;

		for (int i = 0; i<nTail; i++)
			if (tailX[i] == x&&tailY[i] == y)
				gameOver = true;


	}
	else if ((score >= 6) && (score<8))
	{
		if (x >= width) x = 0;
		else if (x < 0) x = width - 1;
		if (y >= height) y = 0;
		else if (y < 0) y = height - 1;

		if (x == width / 3 || y == height / 2)
			gameOver = true;
		for (int i = 0; i<nTail; i++)
			if (tailX[i] == x&&tailY[i] == y)
				gameOver = true;




	}
	else if (score >= 8)
	{
		if (x >= width - 1 || x <= 0)
			gameOver = true;
		if (y >= height || y <= 0)
			gameOver = true;
		if ((x == width / 4 && y>height / 2 - 2) || (x == width / 4 * 2 && y>height / 2 - 2) || (x == width / 4 * 3 && y>height / 2 - 2) || (y == height / 3 - 2 && x>4 && x<width - 4))
			gameOver = true;
		for (int i = 0; i<nTail; i++)
			if (tailX[i] == x&&tailY[i] == y)
				gameOver = true;
	}

	if (x == fruitX && y == fruitY)
	{
		score++;
		srand(time(0));

		fruitX = rand() % (width - 1);
		if (fruitX == 0) fruitX++;
		srand(time(0));
		fruitY = rand() % (height - 1);
		if (fruitY == 0)fruitY++;

		nTail++;

	}


}
void Logic2()
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
		gameOver = true;
		cout << endl << "YOU WON";
	}
	if (y >= height - 1 || y <= 0)
	{
		gameOver = true;
		cout << endl << "YOU WON";
	}

	for (int i = 0; i<nTail; i++)
		if (tailX[i] == x&&tailY[i] == y)
		{
			gameOver = true;
			cout << endl << "YOU WON";
		}

	for (int i = 0; i<nTail1; i++)
		if (tailX1[i] == x&&tailY1[i] == y)
		{
			gameOver = true;
			cout << endl << "YOU WON";
		}


	if (x == fruitX && y == fruitY)
	{

		fruitX = rand() % (width - 2);






		fruitY = rand() % (height - 2);



		while (fruitX == 0 || fruitY == 0 || fruitX == x || fruitY == y)
		{
			fruitX = rand() % (width - 1);

			fruitY = rand() % (height - 1);



		}
		nTail++;


	}
}
void Input_AI()
{
	int k, ok, q;
	if (y<fruitY)
		dir = DOWN;
	else if (x<fruitX)
		dir = RIGHT;
	else

		if (y>fruitY)
			dir = UP;
		else if (x>fruitX)
			dir = LEFT;

	prevdir = dir;

	k = 0;
	ok = 0;
	while (ok == 0)
	{
		ok = 1;
		for (q = 0; q<nTail; q++)
			if ((tailX[q] == x + 1 && tailY[q] == y&&dir == RIGHT) || (tailX[q] == x - 1 && tailY[q] == y&&dir == LEFT)
				|| (tailX[q] == x&&tailY[q] == y + 1 && dir == DOWN) || (tailX[q] == x&&tailY[q] == y - 1 && dir == UP) ||
				(x + 1 == width - 1 && dir == RIGHT) || (x == 1 && dir == LEFT) || (y == 1 && dir == UP) || (y == height - 2 && dir == DOWN))
				ok = 0;

		if (ok == 0)
		{
			if (k % 4 == 0)
				dir = UP;
			if (k % 4 == 1)
				dir = RIGHT;
			if (k % 4 == 2)
				dir = DOWN;
			if (k % 4 == 3)
				dir = LEFT;
		}
		k++;
		if (k == 25)gameOver = true;
	}

	int ii;
	for (q = 0; q<nTail; q++)
		if (prevdir == UP && ((tailX[q] == x&&tailY[q] == y - 1)))
		{
			if (dir == RIGHT)
			{
				for (ii = 0; ii<width; ii++)
					for (q = 0; q<nTail; q++)
					{
						if (x + ii == tailX[q] && y == tailY[q])
							dir = LEFT;
					}
			}
			else

				if (dir == LEFT)
					for (ii = 0; ii<width; ii++)
						for (q = 0; q<nTail; q++)
						{
							if (x - ii == tailX[q] && y == tailY[q])
								dir = RIGHT;
						}

		}
	for (q = 0; q<nTail; q++)
		if (prevdir == DOWN && ((tailX[q] == x&&tailY[q] == y + 1)))
		{
			if (dir == RIGHT)
			{
				for (ii = 0; ii<width; ii++)
					for (q = 0; q<nTail; q++)
					{
						if (x + ii == tailX[q] && y == tailY[q])
							dir = LEFT;
					}
			}
			else

				if (dir == LEFT)
					for (ii = 0; ii<width; ii++)
						for (q = 0; q<nTail; q++)
						{
							if (x - ii == tailX[q] && y == tailY[q])
								dir = RIGHT;
						}


		}


	for (q = 0; q<nTail; q++)
		if (prevdir == RIGHT && ((tailX[q] == x + 1 && tailY[q] == y)))
		{
			if (dir == DOWN)
			{
				for (ii = 0; ii<height; ii++)
					for (q = 0; q<nTail; q++)
					{
						if (y + ii == tailY[q] && x == tailX[q])
							dir = UP;
					}
			}
			else

				if (dir == UP)
					for (ii = 0; ii<height; ii++)
						for (q = 0; q<nTail; q++)
						{
							if (y - ii == tailY[q] && x == tailX[q])
								dir = DOWN;
						}


		}
	for (q = 0; q<nTail; q++)
		if (prevdir == LEFT && ((tailX[q] == x - 1 && tailY[q])))
		{
			if (dir == UP)
			{
				for (ii = 0; ii<height; ii++)
					for (q = 0; q<nTail; q++)
					{
						if (y - ii == tailY[q] && x == tailX[q])
							dir = DOWN;
					}
			}
			else if (dir == DOWN)
			{
				for (ii = 0; ii<height; ii++)
					for (q = 0; q<nTail; q++)
					{
						if (y + ii == tailY[q] && x == tailX[q])
							dir = UP;
					}



			}

		}
}

void rules()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Rules:\n\n->Use ASDW to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> You will die if you hit the wall or snake's body.\n\n->If you chose to play with the computer ,the scope of the game is the same,     except of the fact that you should eat the fruit before the AI Snake.\n\n Good luck!!!";
	cout << endl;
	Sleep(5000);


}

void speed()
{
	int viteza = 0;
	string Vit[4] =
	{
		"Easy",
		"Medium",
		"Hard",
		"Back"
	};

	while (true)
	{
		system("cls");
		for (int v = 0; v <= 3; v++)
		{
			if (v == viteza)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // textul e ros
				cout << Vit[v] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // textul e alb
				cout << Vit[v] << endl;
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0) // verficam daca sageata "sus" e apasata
			{
				viteza = viteza - 1; // scadem variabila pointer cu 1
				if (viteza == -1) // daca trece de 0, inseamna ca "a iesit din meniu"
				{
					viteza = 3; // astfel il reinitializam cu 1
				}
				break; // intrerupem ciclul infinit (al doilea while)
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				viteza = viteza + 1;
				if (viteza == 4)
				{
					viteza = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) // verificam daca este apasat "ENTER"
			{
				if (viteza == 0)
				{
					system("CLS");
					cout << "Ati ales cea mai mica viteza.";
					viti = 1;
					Sleep(1000);

				}
				else if (viteza == 2)

				{
					system("CLS");
					cout << "Ati ales viteza medie";
					viti = 2;
					Sleep(1000);

				}
				else if (viteza == 2)
				{
					system("CLS");
					cout << "Ati ales cea mai rapid viteza";
					viti = 3;
					Sleep(1000);

				}
				else if (viteza == 3)
					return;
				break;
			}
			Sleep(500);

		}
	}
	return;
}


void mode()
{
	int modul = 0;
	string Mode[4] =
	{
		"Single player",
		"Ai Snake",
		"Player vs computer",
		"Back"
	};

	while (true)
	{
		system("cls");
		for (int m = 0; m <= 3; m++)
		{
			if (m == modul)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // textul e ros
				cout << Mode[m] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // textul e alb
				cout << Mode[m] << endl;
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0) // verficam daca sageata "sus" e apasata
			{
				modul = modul - 1; // scadem variabila pointer cu 1
				if (modul == -1) // daca trece de 0, inseamna ca "a iesit din meniu"
				{
					modul = 3; // astfel il reinitializam cu 1
				}
				break; // intrerupem ciclul infinit (al doilea while)
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				modul = modul + 1;
				if (modul == 4)
				{
					modul = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) // verificam daca este apasat "ENTER"
			{
				if (modul == 0)
				{
					system("CLS");
					cout << "Ati ales single mode.";
					ales = 1;
					Sleep(3000);

				}
				else if (modul == 1)

				{
					system("CLS");
					cout << "Ati ales sa vizionati AI-ul";
					ales = 2;
					Sleep(3000);

				}
				else if (modul == 2)
				{
					system("CLS");
					cout << "Ati ales sa concurati cu AI-ul";
					ales = 3;
					Sleep(3000);

				}
				else if (modul == 3)
					return;
				break;
			}
			Sleep(2000);

		}
	}
	return;
}

int meniu()
{
	int alege = 0; // variabila locala mentionata
	string Menu[6] = // numarul 4  reprezinta numarul de aplicatii a meniului
	{
		"Start Game",
		"Mode",
		"Speed",
		"Rules",
		"Highscores",
		"Exit"
	}; // citirea unui array string prin care retinem partile meniului
	while (true) // intrarea intr-un ciclu infinit
	{
		system("cls"); // stergem ce este scris in consola
		for (int t = 0; t <= 5; t++) // citirea array-ului "Menu" (pornim de la 0 si mergem pana la 3)
		{
			if (t == alege) // daca i corespunde cu variabila pointer..
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << Menu[t] << '\n';

			}
			else //daca nu...
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // textul e alb
				cout << Menu[t] << '\n';
			}
		}
		while (true) // intrarea intr-un ciclu infinit nou
		{
			if (GetAsyncKeyState(VK_UP) != 0) // verficam daca sageata "sus" e apasata
			{
				alege = alege - 1; // scadem variabila pointer cu 1
				if (alege == -1) // daca trece de 0, inseamna ca "a iesit din meniu"
				{
					alege = 5; // astfel il reinitializam cu 3
				}
				break; // intrerupem ciclul infinit (al doilea while)
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				alege = alege + 1;
				if (alege == 6)
				{
					alege = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) // verificam daca este apasat "ENTER"
			{
				if (alege == 0)
				{

					if (viti == 1 && ales == 1)
					{
						power_up_bonus_single();
						power_up_coada_single();
						power_up_slow_single();
						setup();
						while (!gameOver)
						{
							harta();
							Input();
							Logic();
							if (SLOW>0)
							{
								Sleep(400);
								SLOW--;
							}
							Sleep(100);
						}
						if (gameOver)
						{

							system("CLS");
							cout << " YOU LOST!!";
							cout << endl;
							cout << " You have  " << score;
							cout << endl;
							cout << endl;


							highScoresingle();





						}

					}
					else if (viti == 2 && ales == 1)
					{

						setup();
						power_up_bonus_single();
						power_up_coada_single();
						power_up_slow_single();
						while (!gameOver)
						{
							harta();
							Input();
							Logic();
							if (SLOW>0)
							{
								Sleep(400);
								SLOW--;
							}
							Sleep(50);

						}
						if (gameOver)
						{

							system("CLS");
							cout << "YOU LOST!!";
							cout << "You have " << score;
							cout << endl;
							cout << endl;
							highScoresingle();


						}
					}
					else if (viti == 3 && ales == 1)
					{
						setup();
						power_up_bonus_single();
						power_up_coada_single();
						power_up_slow_single();
						while (!gameOver)
						{
							harta();
							Input();
							Logic();
							if (SLOW>0)
							{
								Sleep(400);
								SLOW--;
							}
							Sleep(25);

						}
						if (gameOver)
						{

							system("CLS");
							cout << "YOU LOST!!";
							cout << "You have " << score;
							cout << endl;
							cout << endl;
							highScoresingle();


						}
					}
					else if (viti == 1 && ales == 2)
					{

						setup();


						while (!gameOver)
						{

							Input_AI();
							Logic2();
							harta2();

							Sleep(100);
						}

						if (gameOver)
						{

							system("CLS");
							cout << "AI DIED!!";
							cout << "AI has " << score;
							cout << endl;
						}

					}



					else if (viti == 2 && ales == 2)
					{

						setup();


						while (!gameOver)
						{

							Input_AI();
							Logic2();
							harta2();

							Sleep(50);
						}
						if (gameOver)
						{

							system("CLS");
							cout << "AI DIED!!";
							cout << "AI has " << score;
							cout << endl;



						}

					}
					else if (viti == 3 && ales == 2)
					{
						setup();


						while (!gameOver)
						{

							Input_AI();
							Logic2();
							harta2();

							Sleep(25);
						}
						if (gameOver)
						{

							system("CLS");
							cout << "AI DIED!!";
							cout << "AI has " << score;
							cout << endl;


						}

					}
					else if (viti == 1 && ales == 3)
					{
						power_up_bonus();
						power_up_coada();
						power_up_slow();
						setup_single_vs_ai();
						while (!gameOver)
						{
							harta2();
							Input_AI_single_vs_ai();
							Input_single_vs_ai();

							Logic2();
							Logic_single_vs_ai();

							if (SLOW>0)
							{
								Sleep(400);
								SLOW--;
							}
							Sleep(100);

						}
						if (gameOver)
						{

							system("CLS");
							cout << " YOU LOST!!";
							cout << endl;
							cout << " You have  " << score;
							cout << endl;
							cout << endl;
							highscorevs();


						}
					}
					else if (viti == 2 && ales == 3)
					{
						setup_single_vs_ai();
						while (!gameOver)
						{
							power_up_bonus();
							power_up_coada();
							power_up_slow();
							harta_single_vs_ai();
							Input_AI_single_vs_ai();
							Input_single_vs_ai();

							Logic2();
							Logic_single_vs_ai();

							if (SLOW>0)
							{
								Sleep(400);
								SLOW--;
							}
							Sleep(50);

						}
						if (gameOver)
						{

							system("CLS");
							cout << " YOU LOST!!";
							cout << endl;
							cout << " You have  " << score;
							cout << endl;
							cout << endl;
							highscorevs();


						}
					}
					else if (viti == 3 && ales == 3)
					{
						setup_single_vs_ai();
						while (!gameOver)
						{
							power_up_bonus();
							power_up_coada();
							power_up_slow();
							harta_single_vs_ai();
							Input_AI_single_vs_ai();
							Input_single_vs_ai();

							Logic2();
							Logic_single_vs_ai();
							if (SLOW>0)
							{
								Sleep(400);
								SLOW--;
							}
							Sleep(25);

						}
						if (gameOver)
						{

							system("CLS");
							cout << " YOU LOST!!";
							cout << endl;
							cout << " You have  " << score;
							cout << endl;
							cout << endl;
							highscorevs();


						}
					}
				}

				else if (alege == 1)
					mode();
				else if (alege == 2)
					speed();
				else if (alege == 3)
					rules();
				else if (alege == 4)
					printall();
				else if (alege == 5)
					return 0;
				break;

				// incetinim programul ca sa putem manevra meniul
			}
			Sleep(1000);
		}
	}
}


int main()
{
	cout << "Dati dimensiunile pe care le preferati la consola";
	cout << endl;
	cin >> width;
	cin >> height;

	ifstream fin1("highscore_single.txt");
	ofstream fout1("highscore_single.txt");
	ifstream fin2("highscore_vs.txt");
	ofstream fout2("highscore_vs.txt");



	meniu();
	fin1.close();
	fin2.close();
	fout1.close();
	fout2.close();

	return 0;


}
