#include<iostream>
#include "functions.h"
#include<cstdlib>

bool GameOver = false;
char input;
int Move=0;
int T=0;
int main() // Main functions begins
{	
	std::cout << "\t\t\t\tTicTacToe" << std::endl;
	while(GameOver == false)
	{
		DrawBorad();
		std::cout << "[x or o]: ";
		std::cin >> input;
		std::cout << "1 to 9" << std::endl;
		std::cout << ": ";
		std::cin >> Move;

		Insert(input,Move);
		T=Check(Move);
		std::cout << "Move Left: " << T << std::endl;
		if(Win())
		{
			std::cout << "WON!" << std::endl;
			GameOver = true;
		}
	}
	system("pause");
	return 0; // returns 0 -- successo
}
