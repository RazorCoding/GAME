#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define COL 3
#define ROW 5

// Varibales
char Map[COL][ROW] = {{'-','|','-','|','-'},
	{'-','|','-','|','-'},
	{'-','|','-','|','-'}};
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
			if(Map[i][y] == '-')
			{
				t++;
			}
		}
	}
	return t;
}
void Insert(char m, int T)
{
	while(m == 'x' || m == 'o')
	{
		switch(T)
		{
			case 1: // Colum 0
				Map[0][0] = m;
				break;
			case 2:
				Map[0][2] = m;
				break;
			case 3: 
				Map[0][4] = m;
				break;
			case 4: // Colum 1
				Map[1][0] = m;
				break;
			case 5:
				Map[1][2] = m;
				break;
			case 6:
				Map[1][4] = m;
				break;
			case 7:  // Colum 2
				Map[2][0] = m;
				break;
			case 8:
				Map[2][2] = m;
				break;
			case 9:
				Map[2][4] = m;
				break;
			default:
				std::cerr << "Error in copying char to Map" << std::endl;
		}

		m = '-';
	}
}

bool Win()
{
	/*
	   -|-|-
	   -|-|-   Map[3][5];
	   -|-|-
	 */
	std::cout << "Combination checking for x" << std::endl;
	// Horiznotal lines
	if(Map[0][0] == 'x' &&  Map[0][2] == 'x' &&  Map[0][4] == 'x'){
		return true;
	}else if(Map[1][0] == 'x' && Map[1][2] == 'x' && Map[1][4] == 'x' ){
		return true;
	}else if(Map[2][0] == 'x' && Map[2][2] == 'x' && Map[2][4] == 'x' ){		     return true;
	}

	// Cross lines
	else if(Map[0][0] == 'x' && Map[1][2] == 'x' && Map[2][4] == 'x' ){
		return true;	
	}else if(Map[0][4] == 'x' && Map[1][2] == 'x' && Map[2][0] == 'x' ){
		return true;
	}

	// vertical lines
	else if(Map[0][0] == 'x'  && Map[1][0] == 'x' && Map[2][0] == 'x')
	{
		return true;
	}
	else if(Map[0][2] == 'x'  && Map[1][2] == 'x' && Map[2][2] == 'x' ){
		return true;
	}
	else if(Map[0][4]== 'x' && Map[1][4] == 'x' && Map[2][4] == 'x'){
		return true;
	}
	else
	{
		// Horizontal lines
		std::cout << "Combination Checking for o" << std::endl;
		if(Map[0][0] == 'o' && Map[0][2] == 'o' && Map[0][4] == 'o')
		{
			return true;
		}else if(Map[1][0] == 'o' && Map[1][2] == 'o' && Map[1][4] == 'o')
		{
			return true;
		}else if(Map[2][0] == 'o' && Map[2][2] == 'o' && Map[2][4] == 'o')		{
			return true;
		}

		// Cross lines
		else if(Map[0][0] == 'x' && Map[1][2] == 'x' && Map[2][4] == 'x')
		{
			return true;
		}else if(Map[0][4] == 'x' && Map[1][2] == 'x' && Map[2][0] == 'x')
		{
			return true;
		}

		// Verticals lines
		else if(Map[0][0] == 'o'  && Map[1][0] == 'o' && Map[2][0] == 'o')
		{
			return true;
		}
		else if(Map[0][2] == 'o'  && Map[1][2] == 'o' && Map[2][2] == 'o' )		{
			return true;
		}

		else if(Map[0][4]== 'o' && Map[1][4] == 'o' && Map[2][4] == 'o')		{
			return true;
		}

	}
	return false;	
}
#endif
