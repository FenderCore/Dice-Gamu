#include <iostream>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <windows.h>
#include <iomanip>  
using namespace std;

char turn = 'x';
int round = 0;
char board[9] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };

void update()
{
	for(int i = 0; i < 9; i+=3)
	{
		cout << "    |    |   ";
		cout << endl;
		cout << "  " << board[i] << " |";
		cout << "  " << board[i+1] << " |";
		cout << "  " << board[i+2]   << endl;
		cout << "    |    |   "  << endl;
		cout << "";
		if(i < 6)
		{
			for(int i = 0; i < 15; i++)
				cout << "-";
			cout << endl;
		}
	}
	cout << "    |    |   ";
	cout << endl;
}

void updateWin(int type, int vari)
{
	int e = 0;
	for(int i = 0; i < 3; i++)
	{
		cout << "     |     |    "  << endl;
		for(int x = 0; x < 3; x++)
		{
			
	string str = "  "; 
			if(type == 0)
			{
				if(vari == i)
					str = "==";
			} else if (type == 1)
			{
				if(vari == x)
					str = "==";
			} else {
				if(e == 4)
					str = "==";
				if(vari == 0)
				{
					if(e == 0 || e == 8)
						str = "==";
				} else
					if(e == 2 || e == 6)
						str = "==";
			}
			cout << str << board[e] << str;
			if(x != 2) cout << "|";
			e++;
		}
		cout << endl << "     |     |    "  << endl;
		if(i != 2)
			for(int i = 0; i < 18; i++)
				cout << "-";
		cout << endl;
	}
	cout << endl;
}

bool checkWin(char c)
{
	//Horizontal
	for(int i = 0; i < 9; i+=3)
		if(board[i] == c && board[i+1] == c && board[i+2] == c)
		{
			updateWin(0, i/3);
			cout << "Horizontal Win!" << endl;
			return true;
		}
	//Vertical
	for(int i = 0; i < 3; i++)
		if(board[i] == c && board[i+3] == c && board[i+6] == c)
		{
			updateWin(1, i);
			cout << "Vertical Win!" << endl;
		return true;
		}

	if(board[0] == c && board[4] == c && board[8] == c)
	{
		updateWin(2, 0);
		cout << "Diagonal Win!" << endl;
		return true;
	}
	if(board[2] == c && board[4] == c && board[6] == c)
	{
		updateWin(2, 1);
		cout << "Diagonal Win!" << endl;
		return true;
	}
	return false;
}

int main ()
{
	//srand(time(NULL));
	cout << "Welcome to Peter von Wilfenhelm's Tic Tac Toe 2015! \n";
	while(true) 
	{
		update();
		//updateWin(1, 0);
		if(turn == 'x')
			cout << "x turn. ";
		else
			cout << "o turn. ";
		
		cout << "Enter the letter where you would like to go" << endl;
		string input = "hello";
		cin  >> input;
		bool valid = false;
		if(input.length() == 1)
		{
			for(int i = 0; i < 9; i++)
			{
				if(input.at(0) == 'o' || input.at(0) == 'x')
				{
					break;
				}
				if(input.at(0) == board[i])
				{
					board[i] = turn;
					valid = true;
					break;
				}
			}
			if(valid)
			{
				if(checkWin(turn))
				{
					//update();
					cout << turn << " has won the game!" << endl;
					break;
				}
				
				if(round == 8)
				{
					update();
					cout << "Game has ended with a draw!" << endl;
					break;
				}

				if(turn == 'x')
				{
					turn = 'o';
				}
				else
				{
					turn = 'x';
				}
				round++;
			} else 
				cout << "Invalid Move!" << endl;
		} else 
			cout << "Please enter only 1 letter" << endl;

	}
	system("PAUSE");
	  return 0;
}
