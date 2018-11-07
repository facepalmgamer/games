#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int width = 28;
const int height = 29;
int x, y,score;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
bool dotsOn [754] = {true};

void Setup()
{
	for( int i = 0; i < 754; ++i )
		dotsOn[ i ] = true;
	gameOver = false;
	dir = STOP;
	score = 0;
	//x = width / 2;
	//y = 16;
	x = 1;
	y = 0;
}
void Draw()
{
	system("cls");
	for (int i = 0; i < width; i++)
		cout << "#";
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
		//if(j == 0 && i != 16 && i != 12 && i != 13 && i != 14 && i != 18 && i != 19 && i != 20) you can simplify
		// left wall
		if(j == 0 && i != 13 && !(i >= 9 && i <=11) && !(i >= 15 && i <=17))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
			
		else if (j== 0 && i == 13)
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
			
		// top half of teleport
		//right side
		else if (j >= width - 6 && j <= width - 1 && i == 12)
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if (j >= width - 6 && j <= width - 1 && i == 8)
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if (j == width - 6 && (i >= 9 && i <= 11))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		//left side
		else if (j >= 1 && j <= 5 && i == 12)
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if (j >=  1 && j <= 5 && i == 8)
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if (j == 5 && (i >= 9 && i <= 11))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		//bottom half of tele
		//right side
		else if (j >= width - 6 && j <= width - 1 && i == 14)
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if (j >= width - 6 && j <= width - 1 && i == 18)
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		else if (j == width -6 && (i >= 14 && i <= 18))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		//left side
		else if (j >= 1 && j <= 5 && i == 18)
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if (j >=  1 && j <= 5 && i == 14)
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if (j == 5 && (i >= 14 && i <= 18))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		//top right right square
		else if (j >= 2 && j <= 5 && (i == 3 || i == 1))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		else if ((j == 5 && i == 2 )||(j == 2 && i == 2 ))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		// top right left square
		
		else if (j >= 7 && j <= 11 && (i == 3 || i == 1))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		else if ((j == 7 && i == 2 )||(j == 11 && i == 2 ))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
			
		// top left left square
		else if (j >= 22 && j <= 25 && (i == 3 || i == 1))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		else if ((j == 25 && i == 2 )||(j == 22 && i == 2 ))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		// top left right square
		
		else if (j >= 16 && j <= 20 && (i == 3 || i == 1))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		else if ((j == 16 && i == 2 )||(j == 20 && i == 2 ))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		// top middle
		else if ((j == 13 || j == 14) && (i >= 0 && i <= 3))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		//right wall
		else if (j == width-1 && i != 13 && !(i >= 8 && i <=11) && !(i >= 15 && i <=17))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		//top right bottom rectangle
		
		else if (j >= 22 && j <= 25 && (i == 5 || i == 6))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
				
		//top right bottom rectangle
		else if (j >= 2 && j <= 5 && (i == 5 || i == 6))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		//top center T
		else if (j >= 10 && j <= 17 && (i == 5 || i == 6))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		else if ((j == 13 || j == 14) && (i >= 7 && i <= 9))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		//middle center T
		else if (j >= 10 && j <= 17 && (i == 17 || i == 18))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		else if ((j == 13 || j == 14) && (i >= 19 && i <= 21))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
			
		//top center T
		else if (j >= 10 && j <= 17 && (i == 23 || i == 24))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		else if ((j == 13 || j == 14) && (i >= 25 && i <= 27))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		//left |
		else if ((j == 7 || j == 8) && (i >= 14 && i <= 18))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
			
		//right |
		else if ((j == 19 || j == 20) && (i >= 14 && i <= 18))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		// left |-
		else if ((j == 7 || j == 8) && (i >= 5 && i <= 12))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		else if (j >= 9 && j <= 11 && (i == 8 || i == 9))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		// right -|
		else if ((j == 19 || j == 20) && (i >= 5 && i <= 12))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		else if (j >= 16 && j <= 18 && (i == 8 || i == 9))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		//center square
		else if (j >= 10 && j <= 17 && (i == 11 || i == 15) && !(i == 11 && (j == 14 || j == 13)))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		else if ((j == 10 || j == 17)&& (i >= 11 && i <= 15 ))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		else if ((j == 13 || j == 14) && i == 11)
		{
			cout << "-";
				dotsOn[j+26*i] = false;
		}
			
		//jut
		else if ((i == 24 || i == 23) && (j == 1 || j == 2))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if ((i == 24 || i == 23) && (j == width - 3 || j == width - 2))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if (j >= 7 && j <= 11 && (i == 20 || i == 21))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if (j >= 2 && j <= 11 && (i == 27 || i == 26))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if (j >= 2 && j <= 5 && (i == 20 || i == 21))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if ((j == 5 || j == 4) && (i >= 22 && i <= 24))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		else if ((j == 7 || j == 8) && (i >= 23 && i <= 25))
		{
			cout << "#";
				dotsOn[i+26*j] = false;
		}
		//left bottom
		else if (j >= 22 && j <= 25 && (i == 20 || i == 21))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if (j >= 16 && j <=  25 && (i == 27 || i == 26))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if (j >= 16 && j <= 20 && (i == 20 || i == 21))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		else if ((j == width - 6 || j == width - 5) && (i >= 22 && i <= 24))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
			
		else if ((j == width - 8 || j == width - 9) && (i >= 23 && i <= 25))
		{
			cout << "#";
				dotsOn[j+26*i] = false;
		}
		
		
		
		
			
		// right tele	
		else if (j== width - 1 && i == 13)
		{
			cout << "|";
				dotsOn[j+26*i] = false;
		}
			
			
		else if(j == x && i == y)
		{
			cout << "P";
			dotsOn[j+26*i] = false;
		}
		else if(dotsOn[j+26*i] == false)
		cout << " ";
		
		
		 if (dotsOn[j + 26*i] == true)
			{
			/*	for (int k = 0; k < 26; k++)
					for (int l = 0; l < 29; l++)
						if (i == dotsY[l] && j == dotsX[k] && dotsOn[] == Ture)*/
							cout << ".";
							if (x+26*y == j+26*i)
								dotsOn[j+26*i] = false;
							
			}
	
		
		
		}
		cout << endl;
	}
		for (int i = 0; i < width; i++)
		cout << "#";
		cout << "\nX = " << x << " Y = " << y << endl;
}
void Input()
{
		if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 27:
			gameOver = true;
			break;
		}
	}
}
void Logic()
{
	
	switch(dir)
	{
		case UP:
			x--;
			if ((y == 4 && (x == 0 || x == 5 || x == 11 || x == 14 || x == 20 || x == 25))
			|| (y == 7 && (x == 0 ||x == 5 ||x == 8 ||x == 17 ||x == 20 ||x == 25))
			|| (y == 10 && (x == 5 ||x == 11 ||x == 14 ||x == 20))
			|| (y == 13 && (x == 5 ||x == 8 ||x == 17 ||x == 20))
			|| (y == 16 && (x == 5 ||x == 8 ||x == 17 ||x == 20))
			|| (y == 19 && (x == 5 ||x == 8 ||x == 17 ||x == 20))
			|| (y == 22 && (x == 0 ||x == 5 ||x == 14 ||x == 20 ||x == 25 || x == 11))
			|| (y == 25 && (x == 2 ||x == 5 ||x == 8 ||x == 17 ||x == 20 ||x == 23))
			|| (y == 28 && (x == 0 ||x == 11 ||x == 14 ||x == 25))
			|| (!(y== 0|| y== 4|| y== 7|| y== 10|| y== 13|| y== 16|| y== 19|| y== 22||y== 25||y== 28 )))
			y--;
			x++;
			dir = STOP;
			break;
		case DOWN:
			if ((y == 0 && (x == 1 || x == 6 || x == 12 || x == 15 || x == 21 || x == 26))
			|| (y == 4 && (x == 1 ||x == 6 ||x == 9 ||x == 18 ||x == 21 ||x == 26))
			|| (y == 7 && (x == 6 ||x == 12 ||x == 15 ||x == 21))
			|| (y == 10 && (x == 6 ||x == 9 ||x == 18 ||x == 21))
			|| (y == 13 && (x == 6 ||x == 9 ||x == 18 ||x == 21))
			|| (y == 16 && (x == 6 ||x == 9 ||x == 18 ||x == 21))
			|| (y == 19 && (x == 1 ||x == 6 ||x == 12 ||x == 15 ||x == 21 || x == 26))
			|| (y == 22 && (x == 3 ||x == 6 || x == 9 ||x == 12 ||x == 15 ||x == 21 ||x == 24))
			|| (y == 25 && (x == 1 ||x == 12 ||x == 15 ||x == 26))
			|| (!(y== 0|| y== 4|| y== 7|| y== 10|| y== 13|| y== 16|| y== 19|| y== 22||y== 25||y== 28 )))
			y++;
			dir = STOP;
			break;
		case LEFT:
			if ((y == 0 && !(x ==1 || x ==15 )) 
			|| (y == 4 && !(x ==1)) 
			|| (y == 7 && !(x== 21 || x == 15 || x == 9 || x == 1)) 
			|| (y == 10 && !(x == 6 || x == 9 || x == 21)) 
			|| (y == 13 && !(x==18)) 
			|| (y == 16 && !(x == 6 || x == 9 || x == 21)) 
			|| (y == 19 && !(x == 1 || x == 15)) 
			|| (y == 22 && !(x == 1 || x == 24 || x == 6)) 
			|| (y == 25 && !(x == 21 || x == 15 || x== 9 || x == 1)) 
			|| (y == 28 && !(x == 1)))
			x--;
			dir = STOP;
			break;
		case RIGHT:
			if ((y == 0 && !(x ==12 || x ==26 )) 
			|| (y == 4 && !(x ==26)) 
			|| (y == 7 && !(x== 26 || x == 18 || x == 12 || x == 6)) 
			|| (y == 10 && !(x == 6 || x == 18 || x == 21)) 
			|| (y == 13 && !(x==9)) 
			|| (y == 16 && !(x == 6 || x == 18 || x == 21)) 
			|| (y == 19 && !(x == 26 || x == 12)) 
			|| (y == 22 && !(x == 3 || x == 21 || x == 26)) 
			|| (y == 25 && !(x == 26 || x == 18 || x== 12 || x == 6)) 
			|| (y == 28 && !(x == 26)))
			x++;
			dir = STOP;
			break;
			default:
				break;
	}
	if(x == width-1 || y == height-1 || x == 0 || y == 0)
		dir = STOP;
	if (x == 0 && y == 13)
		x = 29;
	if (x == 28 && y == 13)
		x = 0;
	if (x < 0)
		x = 0;
	if (x > width - 1)
		x = width - 1;
	if (y < 0)
		y = 0;
	if (y > height - 1)
		y = height - 1;
//	if (x+y == dotsOn[])

}
int main()
{
	Setup();
	Draw();
	while (!gameOver )
	{
		
		Draw();
		Input();
		Logic();
		Sleep(60);
	}
	cout << "\nYour score is: " << score << endl;
	Sleep(500);
	system("PAUSE");
	return 0;
}
