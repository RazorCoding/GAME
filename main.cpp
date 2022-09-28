#include<iostream>
#include<cstdlib>

// Custom libs
#include "functions.h"

bool GameOver = false;
const char P1='x',P2='o';
int Move=0 , Selected=0, MF=0;
int main() // Main functions begins
{

	banner();
	std::cout << "1. Single Player" << std::endl;
	std::cout << "2. Double Player" << std::endl;
	std::cout  << "Select Number: ";
	std::cin  >> Selected;
	std::cout << std::endl;
	switch(Selected)
	{
		case 1:

			std::cout << "P1 is 'x'" << std::endl << "P2 is 'o'" << std::endl;
			while(!GameOver){
				DrawBorad();
				std::cout << "P1 Move: ";
				std::cin  >> Move;
				MoveLeft(Move);
					if(check(Move,P1)){ 				
						InsertMove(P1,Move);
						DrawBorad();
						
						if(Win(P1))
							{
								GameOver=true;
								break;
							}
					}
				
				
				Move = 0; // Reseting Value of Move Variable					
				
				std::cout << "P2 Move: ";
				std::cin >> Move;
				MoveLeft(Move);

				if(check(Move,P2))
				{
					InsertMove(P2,Move);
					DrawBorad();
					MoveLeft(Move);
					if(Win(P2))
					{
							GameOver = true;
							break;
					}
				}				
			}
	}
system("pause");
	return 0; // returns 0 -- success
}
