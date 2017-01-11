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