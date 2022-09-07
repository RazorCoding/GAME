#include<iostream>
#include "functions.h"
#include<cstdlib>

bool GameOver = false;
char Player1,Player2;
int Move=0 , i=0;
int main() // Main functions begins
{
	std::cout << "\t\t\t\t\tTicTacToe" << std::endl;
	std::cout << "1. Double player" << std::endl;
	std::cout << "2. Single player" << std::endl;
	std::cin >> i;
	switch(i)
	{
		case 1:
			std::cout << "Chosse: x/o" << std::endl;
			std::cout << "Player 1: ";
			std::cin  >> Player1;
			std::cout << "Player 2: ";
			std::cin  >> Player2;
			if(Player1 == 'x' && Player2 == 'o')
			{
				std::cout << "Player 1: " << Player1 << "Player 2: " << Player2 << std::endl;
			}else 
			{
				std::cerr  << "Choose x/o" << std::endl;
			}

		case 2:
			std::cout << "Setting up Computer function" << std::endl;
			Player1 = 'x'; // Setting player1 variable to x
			Player2 = 'o'; // Setting Player2 varibale to o

	} 
	while(!GameOver)
	{
		if(i == 1)
		{
			DrawBorad();
			std::cout << "Player 1 Turn" << std::endl;
			std::cout << "Move: 1-9 " << std::endl <<  ": " << std::endl;
			std::cin >> Move;
			Insert(Player1,Move);
			DrawBorad();
			if(Win(Player1))
			{
				std::cout << "Player 1 is the winner. " << Player1 << std::endl;
			}

			std::cout << "Player 2 Turn " << std::endl;
			std::cout << "Move: 1-9" << std::endl <<  ": " << std::endl;
			std::cin >> Move;
			Insert(Player2,Move);
			DrawBorad();
			if(Win(Player2))
			{
				std::cout << "Player 2 is the winner. " << Player2  << std::endl;
			}
		}else if(i == 2)
		{
			while(!GameOver)
			{
				DrawBorad();
				std::cout << "Your Move: 1-9" << std::endl;
				std::cout << " : ";
				std::cin >> Move;
				Insert(Player1,Move);
				std::cout << std::endl;
				std::cout << "Computer Move: " << std::endl;
				ComputerMove(Player2);
				DrawBorad();
			}
		}
	}
		return 0; // returns 0 -- successo
	}
