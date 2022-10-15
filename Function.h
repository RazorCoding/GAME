#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <string>
#include <limits>

#define COL 3
#define ROW 5

// Functions Declaration
void banner();
bool DrawBorad();
int MoveLeft(int);
void InsertMove(char, int);
void ComputerMove();
bool Win(char);
bool check(int, char);
void ResetBorad();
void Computer(char);
void Starline(int);
void SinglePlayerMode();
void DoublePlayerMode();
void Rplay();
void CharecterChange();
void GameOn();
void Setting();

// Static variables
static bool GameOver = false;
// default Value x and o
static int Sel = 0;
static int Sel1 = 0;
static char P1 = 'x';	 // Player 1
static char P2 = 'o';	 // Player 2
static int Move = 0;	 // Move store
static int Selected = 0; // Choice store
static char RInput;		 // restart game varibale
static char CInput;		 // Character change variable
// Map Array
char Map[COL][ROW] = {{'-', '|', '-', '|', '-'},
					  {'-', '|', '-', '|', '-'},
					  {'-', '|', '-', '|', '-'}};
void GameOn()
{
jump:
	banner();

	std::cout << "1.Single Player Mode" << std::endl;
	Starline(20);
	std::cout << "2.Double Player Mode" << std::endl;
	Starline(20);
	std::cout << "3.Settings" << std::endl;
	Starline(20);
	std::cout << "1-3: ";

	do
	{
		std::cin >> Sel;
		// std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (std::cin.fail());

	switch (Sel)
	{
	case 1:
		SinglePlayerMode();
		Rplay();
		break;
	case 2:
		DoublePlayerMode();
		Rplay();
		break;
	case 3:
		Starline(50);
		std::cout << "\t\t\t\tSettings\n";
		Starline(50);
		std::cout << "1.Change Charecter\n"
				  << std::endl;
		Starline(20);
		std::cin >> Sel1;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cin >> Sel1;
		}

		switch (Sel1)
		{
		case 1:
			Setting();
			goto jump;
			break;
		default:
			std::cout << "1-1" << std::endl;
		}
		break;
	default:
		std::cout << "1-3" << std::endl;
	}
}
void Setting()
{
	CharecterChange();
}

void CharecterChange()
{
	std::cout << " Character Change y/n" << std::endl;
	std::cout << "1: ";
	std::cin >> CInput;
	switch (CInput)
	{
	case 'y':
	case 'Y':
		std::cout << "P1: ";
		std::cin >> P1;
		std::cout << "P2: ";
		std::cin >> P2;
		break;
	case 'n':
	case 'N':
		break;
	default:
		while (CInput != 'Y' || CInput != 'y' || CInput != 'N' || CInput != 'n')
		{
			std::cout << "y/n" << std::endl
					  << ": ";
			std::cin >> CInput;
		}
	}
}
void SinglePlayerMode()
{
	GameOver = false;
	while (!GameOver)
	{
		Computer(P2);
		if (Win(P2))
		{
			Starline(30);
			std::cout << "Computer Wins " << P2 << std::endl;
			DrawBorad();
			Starline(30);

			GameOver = true;
			break;
			Rplay();
			ResetBorad();
		}

		DrawBorad();
		std::cout << "P1 " << P1 << " Move: ";
		std::cin >> Move;

		int t = MoveLeft(Move);
		if (t == 0)
		{
			GameOver = true;
			break;
		}
		if (check(Move, P1))
		{
			InsertMove(P1, Move);
			DrawBorad();

			if (Win(P1))
			{
				std::cout << "Winner is " << P1 << std::endl;
				Starline(30);
				DrawBorad();
				Starline(30);

				GameOver = true;
				break;
				Rplay();
				ResetBorad();
			}
		}
	}
}
void Rplay()
{
	std::cout << "Re-play: y/n" << std::endl;
	std::cin >> RInput;

	switch (RInput)
	{
	case 'y':
	case 'Y':
		ResetBorad();
		GameOn();
		break;

	case 'n':
	case 'N':
		GameOver = true;
		break;
	default:
		while (RInput != 'Y' || RInput != 'y' || RInput != 'N' || RInput != 'n')
		{
			std::cout << "y/n" << std::endl
					  << ": ";
			std::cin >> RInput;
		}
	}
}
void DoublePlayerMode()
{
	while (!GameOver)
	{

		DrawBorad();
		std::cout << P1 << " [1-9]: ";
		std::cin >> Move;

		int t = MoveLeft(Move);
		if (t == 0)
		{
			GameOver = true;
			break;
		}
		if (check(Move, P1))
		{
			InsertMove(P1, Move);
			DrawBorad();

			if (Win(P1))
			{
				GameOver = true;
				break;
				Rplay();
			}
		}

		Move = 0; // Reseting Value of Move Variable

		std::cout << P2 << " [1-9]: ";
		std::cin >> Move;
		MoveLeft(Move);

		if (check(Move, P2))
		{
			InsertMove(P2, Move);
			DrawBorad();
			MoveLeft(Move);
			if (Win(P2))
			{
				GameOver = true;
				break;
				Rplay();
			}
		}
	}
}
void Starline(int y)
{
	for (int i = 0; i < y; i++)
	{
		std::cout << "*";
	}
	std::cout << std::endl;
}
void banner()
{
	Starline(80);
	std::cout << R"(

████████╗██╗ ██████╗████████╗ █████╗  ██████╗████████╗ ██████╗ ███████╗
╚══██╔══╝██║██╔════╝╚══██╔══╝██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██╔════╝
   ██║   ██║██║        ██║   ███████║██║        ██║   ██║   ██║█████╗  
   ██║   ██║██║        ██║   ██╔══██║██║        ██║   ██║   ██║██╔══╝  
   ██║   ██║╚██████╗   ██║   ██║  ██║╚██████╗   ██║   ╚██████╔╝███████╗
   ╚═╝   ╚═╝ ╚═════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝
	)" << std::endl;
	Starline(80);
}

void ResetBorad()
{
	// Reseting Characters
	P1 = 'x';
	P2 = 'o';
	// Reseting Map
	for (int i = 0; i < COL; i++)
	{
		for (int t = 0; t < ROW; t++)
		{
			if (Map[i][t] == P1 || Map[i][t] == P2)
			{
				Map[i][t] = '-';
			}
			else
			{
				std::cerr << "Error on updating broad" << std::endl;
			}
		}
	}
}
// TODO: Write Computer Function
void Computer(char s)
{
	bool game = false;
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (Map[i][j] == '-')
			{
				std::cout << "Computer Move Check!" << std::endl;
				Map[i][j] = s;
				game = true;
				break;
			}
		}
		if (game != false)
		{
			break;
		}
	}
}
bool check(int m, char P)
{
	if (m >= 1 && m <= 9)
	{
		std::cout << "Move Check OK!!" << std::endl;
		return true;
	}
	else
	{
		while (m < 1 && m > 9)
		{
			std::cout << "ReEnter you Move: It should be [1-9] " << std::endl;
			std::cout << P << " Move: ";
			std::cin >> m;
			Move = m;
			return true;
		}
	}
	return false;
}
bool DrawBorad()
{
		for(int i = 0; i < COL; i++)
		{
			for (int y = 0; y < ROW; y++)
			{
				std::cout << Map[i][y];
			}
			std::cout << std::endl;
		}
	
	return true;
}
int MoveLeft(int m)
{
	int t = 0; // Move Left
	for (int i = 0; i < COL; i++)
	{
		for (int y = 0; y < ROW; y++)
		{
			if (Map[i][y] == '-')
			{
				t++;
			}
		}
	}
	std::cout << "Move Left " << t << std::endl;
	return t;
}

void InsertMove(char s, int m)
{
	switch (m)
	{
	case 1:
		if (Map[0][0] == '-')
		{
			Map[0][0] = s;
			break;
		}
		else
		{
			if (Map[0][0] == P1 || Map[0][0] == P2)
			{
				std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
				break;
			}
		}
	case 2:
		if (Map[0][2] == '-')
		{
			Map[0][2] = s;
			break;
		}
		else
		{
			if (Map[0][2] == P1 || Map[0][2] == P2)
			{
				std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
				break;
			}
		}
	case 3:
		if (Map[0][4] == '-')
		{
			Map[0][4] = s;
			break;
		}
		else
		{
			if (Map[0][4] == P1 || Map[0][4] == P2)
			{
				std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
				break;
			}
		}
	case 4:
		if (Map[1][0] == '-')
		{
			Map[1][0] = s;
			break;
		}
		else
		{
			if (Map[1][0] == P1 || Map[1][0] == P2)
			{
				std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
				break;
			}
		}
	case 5:
		if (Map[1][2] == '-')
		{
			Map[1][2] = s;
			break;
		}
		else
		{
			if (Map[1][2] == P1 || Map[1][2] == P2)
			{
				std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
				break;
			}
		}
	case 6:
		if (Map[1][4] == '-')
		{
			Map[1][4] = s;
			break;
		}
		else
		{
			if (Map[1][4] == P1 || Map[1][4] == P2)
			{
				std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
				break;
			}
		}
	case 7:
		if (Map[2][0] == '-')
		{
			Map[2][0] = s;
			break;
		}
		else
		{
			if (Map[2][0] == P1 || Map[2][0] == P2)
			{
				std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
				break;
			}
		}
	case 8:
		if (Map[2][2] == '-')
		{
			Map[2][2] = s;
			break;
		}
		else
		{
			if (Map[2][2] == P1 || Map[2][2] == P2)
			{
				std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
				break;
			}
		}
	case 9:
		if (Map[2][4] == '-')
		{
			Map[2][4] = s;
			break;
		}
		else
		{
			if (Map[2][4] == P1 || Map[2][4] == P2)
			{
				std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
				break;
			}
		}
	}
}
bool Win(char s)
{
	// Horiznotal lines
	if (Map[0][0] == s && Map[0][2] == s && Map[0][4] == s)
	{
		std::cout << "Player " << s << " Wins" << std::endl;
		return true;
	}
	else if (Map[1][0] == s && Map[1][2] == s && Map[1][4] == s)
	{
		std::cout << "Player " << s << " Wins" << std::endl;
		return true;
	}
	else if (Map[2][0] == s && Map[2][2] == s && Map[2][4] == s)
	{
		std::cout << "Player " << s << " Wins" << std::endl;
		return true;
	}

	// Cross lines
	else if (Map[0][0] == s && Map[1][2] == s && Map[2][4] == s)
	{
		std::cout << "Player " << s << " Wins" << std::endl;
		return true;
	}
	else if (Map[0][4] == s && Map[1][2] == s && Map[2][0] == s)
	{
		std::cout << "Player " << s << " Wins" << std::endl;
		return true;
	}

	// vertical lines
	else if (Map[0][0] == s && Map[1][0] == s && Map[2][0] == s)
	{
		std::cout << "Player " << s << " Wins" << std::endl;
		return true;
	}
	else if (Map[0][2] == s && Map[1][2] == s && Map[2][2] == s)
	{
		std::cout << "Player " << s << " Wins" << std::endl;
		return true;
	}
	else if (Map[0][4] == s && Map[1][4] == s && Map[2][4] == s)
	{
		std::cout << "Player " << s << " Wins" << std::endl;
		return true;
	}
	return false;
}
#endif
