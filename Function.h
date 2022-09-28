#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define S  2
#define COL 3
#define ROW 5

// Functions Declaration
void banner();
bool DrawBorad();
int MoveLeft(int);
void InsertMove(char , int);
void ComputerMove();
bool Win(char );
bool check(int ,char);


// Map Array
char Map[COL][ROW] = {{'-','|','-','|','-'},
	{'-','|','-','|','-'},
	{'-','|','-','|','-'}};

void banner()
{
	std::cout << R"(

████████╗██╗ ██████╗████████╗ █████╗  ██████╗████████╗ ██████╗ ███████╗
╚══██╔══╝██║██╔════╝╚══██╔══╝██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██╔════╝
   ██║   ██║██║        ██║   ███████║██║        ██║   ██║   ██║█████╗  
   ██║   ██║██║        ██║   ██╔══██║██║        ██║   ██║   ██║██╔══╝  
   ██║   ██║╚██████╗   ██║   ██║  ██║╚██████╗   ██║   ╚██████╔╝███████╗
   ╚═╝   ╚═╝ ╚═════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝
	)" << std::endl;
}
bool check(int m, char P)
{
	if(m >= 1 && m <= 9)
	{
		std::cout << "Move Check OK!!" << std::endl;
		return true;
	}else
	{
		while(m <= 1 || m >= 9)
		{
			std::cout << "ReEnter you Move: It should be [1-9] " << std::endl;
			std::cout << P << " Move: ";
			std::cin  >> m;
			
		}
		if(m >= 1 && m <= 9)
		{
			return true;
		}
	}
	return false;
}
bool DrawBorad()
{
	for(int i=0;i<COL;i++)
	{
		for(int y=0;y<ROW;y++)
		{
			std::cout << Map[i][y];
		}
		std::cout << std::endl;
	}
	return 0;
}
int MoveLeft(int m)
{
	int t=0;
	for(int i=0;i<COL;i++)
	{
		for(int y=0;y<ROW;y++)
		{
			if(Map[i][y] == '-')
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
	switch(m)
	{
		case 1:
			if(Map[0][0] == '-')
			{
				Map[0][0] = s;
				break;
			}else{
				if(Map[0][0] == 'x' || Map[0][0] == 'o')
				{
					std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
					break;
				}
			}
		case 2: 
			if(Map[0][2] == '-')
			{
				Map[0][2] = s;
				break;
			}else{
				if(Map[0][2] == 'x' || Map[0][2] == 'o')
				{
					std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
					break;
				}
			}
		case 3: 
		if(Map[0][4] == '-')
			{
				Map[0][4] = s;
				break;
			}else{
				if(Map[0][4] == 'x' || Map[0][4] == 'o')
				{
					std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
					break;
				}
			}
		case 4:
		if(Map[1][0] == '-')
			{
				Map[1][0] = s;
				break;
			}else{
				if(Map[1][0] == 'x' || Map[1][0] == 'o')
				{
					std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
					break;
				}
			}
		case 5:
		if(Map[1][2] == '-')
			{
				Map[1][2] = s;
				break;
			}else{
				if(Map[1][2] == 'x' || Map[1][2] == 'o')
				{
					std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
					break;
				}
			}
		case 6:
		if(Map[1][4] == '-')
			{
				Map[1][4] = s;
				break;
			}else{
				if(Map[1][4] == 'x' || Map[1][4] == 'o')
				{
					std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
					break;
				}
			}
		case 7:
		if(Map[2][0] == '-')
			{
				Map[2][0] = s;
				break;
			}else{
				if(Map[2][0] == 'x' || Map[2][0] == 'o')
				{
					std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
					break;
				}
			}
		case 8:
			if(Map[2][2] == '-')
			{
				Map[2][2] = s;
				break;
			}else{
				if(Map[2][2] == 'x' || Map[2][2] == 'o')
				{
					std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
					break;
				}
			}
		case 9:
			if(Map[2][4] == '-')
			{
				Map[2][4] = s;
				break;
			}else{
				if(Map[2][4] == 'x' || Map[2][4] == 'o')
				{
					std::cout << "Postion taken!!! Cannot Be filled" << std::endl;
					break;
				}
			}
	}
}
void ComputerMove(char s)
{
	char cp = char('o'); //Defineing Computer charecter

	// Computer Moves if else statements
	// Map first line Block.
	if(Map[0][0] == char(s) && Map[0][2] == char(s))
	{
		Map[0][4] = cp;
	}else if(Map[0][4] == char(s) && Map[0][2] == char(s))
	{
		Map[0][0] = cp;
	}
	// Map Second line Block.
	else if(Map[1][0] == char(s) && Map[1][2] == char(s))
	{
		Map[1][4] = cp;
	}else if(Map[1][4] = char(s) && Map[1][2] == char(s))
	{
		Map[1][0] = cp;
	}
	// Map Thried line Block.
	else if(Map[2][0] == char(s) && Map[2][2] == char(s))
	{
		Map[2][4] = cp;
	}else if(Map[2][4] == char(s) && Map[2][2] == char(s))
	{
		Map[2][0] = cp;
	}
	// Map Vertical First line Block.
	else if(Map[0][0] == char(s) && Map[1][0] == char(s))
	{
		Map[3][0]  = cp;
	}else if(Map[3][0] == char(s) && Map[0][1] == char(s))
	{
		Map[0][0] = cp;
	}
	// Map Vertical second line Block
	else if(Map[0][2] == char(s) && Map[1][2] == char(s))
	{
		Map[2][2] = cp;
	}else if(Map[2][2] == char(s) && Map[1][2] == char(s))
	{
		Map[0][2] = cp;
	}
	// Map Vertical Thrid line block.
	else if(Map[0][4] == char(s) && Map[1][4] == char(s))
	{
		Map[2][4] = cp;
	}else if(Map[2][4] = char(s) && Map[1][4] == char(s))
	{
		Map[0][4] = cp;
	}else {std::cout << "Computer Wins" << std::endl;}

}
bool Win(char s)
{
	/*
	   -|-|-
	   -|-|-   Map[3][5];
	   -|-|-
	 */
	// Horiznotal lines
	if(Map[0][0] == s &&  Map[0][2] == s &&  Map[0][4] == s){
		std::cout << "Player " << s << " Wins" << std::endl;
		return true;
	}else if(Map[1][0] == s && Map[1][2] == s && Map[1][4] == s ){
		std::cout << "Player " << s << " Wins" << std::endl;		
		return true;
	}else if(Map[2][0] == s && Map[2][2] == s && Map[2][4] == s ){	
		std::cout << "Player " << s << " Wins" << std::endl;		
		return true;
	}

	// Cross lines
	else if(Map[0][0] == s && Map[1][2] == s && Map[2][4] == s ){
		std::cout << "Player " << s << " Wins" << std::endl;		
		return true;	
	}else if(Map[0][4] == s && Map[1][2] == s && Map[2][0] == s ){
		std::cout << "Player " << s << " Wins" << std::endl;
		return true;
	}

	// vertical lines
	else if(Map[0][0] == s  && Map[1][0] == s && Map[2][0] == s)
	{
		std::cout << "Player " << s << " Wins" << std::endl;
		return true;
	}
	else if(Map[0][2] == s  && Map[1][2] == s && Map[2][2] == s ){
		std::cout << "Player " << s << " Wins" << std::endl;
		return true;
	}
	else if(Map[0][4]== s && Map[1][4] == s && Map[2][4] == s){
		std::cout << "Player " << s << " Wins" << std::endl;
		return true;
	}
	else{
		return false;
	}
}
#endif
