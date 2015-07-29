// Dice Game.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <windows.h>
using namespace std;

bool playerTurn = true;
float winRate = 0.0f;
int roundNum = 1;
int playerPoints = 0;
int aiPoints = 0;
int playerDie[2];
int aiDie[2];
void animate(int i);

void animate(int i)
{
	if(i == 5)
	{
		cout << "__________ \n";
		cout << "| o     o | \n";
		cout << "|    o    | \n";
		cout << "| o     o | \n";
		cout << "__________ \n";
	} else 
	if(i == 2)
	{
		cout << "__________ \n";
		cout << "| o       | \n";
		cout << "|         | \n";
		cout << "|       o | \n";
		cout << "__________ \n";
	} else 
	if(i == 6)
	{
		cout << "__________ \n";
		cout << "| o     o | \n";
		cout << "| o     o | \n";
		cout << "| o     o | \n";
		cout << "__________ \n";
	} else 
	if(i == 1)
	{
		cout << "__________ \n";
		cout << "|         | \n";
		cout << "|    o    | \n";
		cout << "|         | \n";
		cout << "__________ \n";
	} else 
	if(i == 3)
	{
		cout << "__________ \n";
		cout << "| o       | \n";
		cout << "|    o    | \n";
		cout << "|       o | \n";
		cout << "__________ \n";
	} else 
	if(i == 6)
	{
		cout << "__________ \n";
		cout << "| o     o | \n";
		cout << "|         | \n";
		cout << "| o     o | \n";
		cout << "__________ \n";
	}
}

int roll()
{

	int number = rand() % 6 + 1;
	//Sleep(100);
	return number;
}

void display(string name, int dice1, int dice2)
{
	animate(dice1);
	animate(dice2);
	cout << name << " has rolled a " << dice1 << " and a " << dice2 << " for a total of " << dice1+dice2 << endl;
}

void compare()
{
	int pTotal = playerDie[0] + playerDie[1];
	int aiTotal = aiDie[0] + aiDie[1];
	//Double
	if(playerDie[0] == playerDie[1])
	{
		if(aiDie[0] == aiDie[1])
		{
			playerPoints++;
			cout << "Player has won" << endl;
		} else {
			if(pTotal > aiTotal)
			{
				playerPoints++;
				cout << "Player has won" << endl;
			} else if (pTotal < aiTotal) {
				aiPoints++;
				cout << "AI has won" << endl;
			} else {
				cout << "In the end, we are all losers" << endl;
			}
		}
	} else {
		if(aiDie[0] == aiDie[1])
		{
			aiPoints++;
			cout << "AI has won" << endl;
		} else {
			if(pTotal > aiTotal)
			{
				playerPoints++;
				cout << "Player has won" << endl;
			} else if (pTotal < aiTotal) {
				aiPoints++;
				cout << "AI has won" << endl;
			} else {
				cout << "In the end, we are all losers" << endl;
			}
		}
	}
	roundNum++;

}

void cheat()
{
	winRate = aiPoints / (aiPoints + playerPoints);
	int pTotal = playerDie[0] + playerDie[1];
	//int aiTotal = aiDie[0] + aiDie[1];
	if(winRate >= 0.69f)
	{
		for(int i = 0; i < 2; i++)
			{
				aiDie[i] = roll();
			}
	} else {
		if(playerDie[0] == playerDie[1])
		{
			if(playerDie[0] == 6)
			{
				aiDie[0] = 6;
			} else {
				
				aiDie[0] = playerDie[0] + 1;
			}
			aiDie[1] = aiDie[0];
		} else {
			aiDie[0] = playerDie[0] + 1;
			aiDie[1] = roll();
		}
	}
}

int main ()
{
	srand(time(NULL));
	cout << "Welcome to Peter von Wilfenhelm's Dice Challenge 2015! \n";
	//while(true) 
	for(int i = 0; i < 1000; i++)
	{
		cout << "Round " << roundNum << endl << "Player: " << playerPoints << endl << "AI: " << aiPoints << " AI Winrate: " << winRate << endl;
		cout << "Type roll \n";
		string input = "roll";
		//cin >> input;
		if(!input.compare("roll"))
		{
			for(int i = 0; i < 2; i++)
			{
				playerDie[i] = roll();
			}
			display("Player", playerDie[0], playerDie[1]);
			
			if(roundNum < 5)
			{
				for(int i = 0; i < 2; i++)
				{
					aiDie[i] = roll();
				}
			} else 
				cheat();
			display("AI", aiDie[0], aiDie[1]);
			compare();
			//Sleep(200);
		} else if(!input.compare("exit")) 
		{
			cout << "Your a fucking quitter faggot! \n";
			system("PAUSE");
			break;
		}
	}
	system("PAUSE");
	  return 0;
}

