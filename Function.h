#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define S  2
#define COL 3
#define ROW 5

// Map Array
char Map[COL][ROW] = {{'-','|','-','|','-'},
	{'-','|','-','|','-'},
	{'-','|','-','|','-'}};

// Draw Map Funciton.

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
int Check(int m)
{
	int t=0;
	for(int i=0;i<COL;i++)
	{
		for(int y=0;y<ROW;y++)
		{
			if(Map[i][y] == ' ')
			{
				t++;
			}
		}
	}
	return t;
}

void Insert(char s, int m)
{
	switch(m)
	{
		case 1:
			Map[0][0] = s;
			break;
		case 2: 
			Map[0][2] = s;
			break;
		case 3: 
			Map[0][4] = s;
			break;
		case 4:
			Map[1][0] = s;
			break;
		case 5:
			Map[1][2] = s;
			break;
		case 6:
			Map[1][4] = s;
			break;
		case 7:
			Map[2][0] = s;
			break;
		case 8:
			Map[2][2] = s;
			break;
		case 9:
			Map[2][4] = s;
			break;
		default:
			std::cerr << "Wrong Number" << std::endl;
			break;
	
	}
}
void ComputerMove(char SelectedPlayer)
{
	int temp[2];
	int *p = new int;
	// Searching for empty block
	for(int i=0;i<COL;i++)
	{
		for(int y=0;y<ROW;y++)
		{
			if(Map[i][y] == '-')
			{
				temp[0] = i;
				temp[1] = y;
				break;
			}else{std::cout << "Its not assigning." << std::endl;}
		}
	}
	Map[temp[0]][temp[1]] = SelectedPlayer;
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
		return true;
	}else if(Map[1][0] == s && Map[1][2] == s && Map[1][4] == s ){
		return true;
	}else if(Map[2][0] == s && Map[2][2] == s && Map[2][4] == s ){		     return true;
	}

	// Cross lines
	else if(Map[0][0] == s && Map[1][2] == s && Map[2][4] == s ){
		return true;	
	}else if(Map[0][4] == s && Map[1][2] == s && Map[2][0] == s ){
		return true;
	}

	// vertical lines
	else if(Map[0][0] == s  && Map[1][0] == s && Map[2][0] == s)
	{
		return true;
	}
	else if(Map[0][2] == s  && Map[1][2] == s && Map[2][2] == s ){
		return true;
	}
	else if(Map[0][4]== s && Map[1][4] == s && Map[2][4] == s){
		return true;
	}
	else
	{
		// Horizontal lines
		if(Map[0][0] == s && Map[0][2] ==  s && Map[0][4] == s)
		{
			return true;
		}else if(Map[1][0] == s && Map[1][2] == s && Map[1][4] == s)
		{
			return true;
		}else if(Map[2][0] == s && Map[2][2] == s && Map[2][4] == s)		{
			return true;
		}

		// Cross lines
		else if(Map[0][0] == s && Map[1][2] == s && Map[2][4] == s)
		{
			return true;
		}else if(Map[0][4] == s && Map[1][2] == s && Map[2][0] == s)
		{
			return true;
		}

		// Verticals lines
		else if(Map[0][0] == s  && Map[1][0] == s && Map[2][0] == s)
		{
			return true;
		}
		else if(Map[0][2] == s  && Map[1][2] == s && Map[2][2] == s )		{
			return true;
		}

		else if(Map[0][4]== s && Map[1][4] == s && Map[2][4] == s)		{
			return true;
		}

	}
	return false;	
}
#endif
