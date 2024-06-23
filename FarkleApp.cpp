#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Farkle.h"
#include <ctime>
#include <cstdlib>
using namespace std;

// Task 1 creating main menu
int Farkle::runMenu()
{
	int count = 0;
	while (count <= 40) {

		cout << "#";
		count++; //increasing count.. count=count+1
	};
	cout << endl;

	cout << "************FARKLE MAIN MENU************" << endl;

	count = 0;
	while (count <= 40) {

		cout << "#";
		count++; //increasing count.. count=count+1
	};
	cout << endl;

	cout << "(1) Game Rules" << endl;
	cout << "(2) View Extra Functionalities" << endl;
	cout << "(3) Play Farkle" << endl;
	cout << endl;

	count = 0;
	while (count <= 40) {

		cout << "#";
		count++; //increasing count.. count=count+1
	};
	cout << endl;
	cout << endl;

	cout << "Enter a option (1-3)?" << endl;
	int opt;
	cin >> opt;

	return opt;


}

void Farkle::displayRules()
{
	fstream displayrule; //creating an object to use for furthee functions involving files
	displayrule.open("GameRules.txt", ios::in); //assigning game rules to displayrule object and opening textfile to read information 
	string words;
	if (displayrule.is_open()) //checking if text file is open
	{
		getline(displayrule, words); //assigning first line of displayrule to words
		while (displayrule)
		{
			cout << words << endl;
			getline(displayrule, words);  //looping until all the lines have been displayed

		}

		displayrule.close(); //closing file
	}
	else{
		cout << "no file found" <<endl;
		
	}

}

void Farkle::displayfunction()
{
	fstream displayfunc; //creating an object to use for furthee functions involving files
	displayfunc.open("ExtraFunctional.txt", ios::in); //assigning game rules to displayrule object and opening textfile to read information 
	string words;
	if (displayfunc.is_open()) //checking if text file is open
	{
		getline(displayfunc, words); //assigning first line of displayrule to words
		while (displayfunc)
		{
			cout << words << endl;
			getline(displayfunc, words);  //looping until all the lines have been displayed

		}

		displayfunc.close(); //closing file
	}

}


void Farkle::playFarkle(bool lock[], int dicevalue[], int max)
{
	for (int i = 0; i < 7; i++)
	{
		dicevalue[i] = 0;
	}
	srand(time(NULL)); //to variate the random result
	for (int j = 0; j < 7; j++)
	{
		rolldice(dicevalue, lock, j);
	}
	for (int i = 1; i < 7; i++)
	{

		cout << "dicevalue," << i << "=" << dicevalue[i] << endl;
	}

	int turns = 0;
	int totalp = 0; //totalpoints for the match
	while (userwins(dicevalue) > 0)
	{
		if (userwins(dicevalue) > 0)
		{
	
			if (totalp < max)
			{
				cout << "Bank Points and continue playing?(Press 'Y' for yes and any key for no)" << endl;
				char choice;
				cin >> choice;
				int lockvalue;
				lockvalue = 1;

				if (choice == 'y')
				{
					totalp = totalp + userwins(dicevalue);

					for (int j = 0; j < 7; j++)
					{
						rolldice(dicevalue, lock, j);
					}

					for (int p = 1; p < 7; p++)
					{
						printlock(lock, dicevalue, p);
					}

				}

				else
				{

					while (lockvalue > 0 and lockvalue < 7)
					{
						cout << "Enter value(1-6) for locking and any other number to continue:" << endl;
						cin >> lockvalue;
						if (lockvalue > 0 and lockvalue < 7)
						{
							locking(lock, lockvalue);

						}
						else
						{
							break;
						}
					}
					cout << "Press 'y' to roll again and any key to bank and score" << endl;
					char vary;
					cin >> vary;
					if (vary == 'y')
					{
						for (int j = 0; j < 7; j++)
						{
							rolldice(dicevalue, lock, j);
						}

						for (int p = 1; p < 7; p++)
						{
							printlock(lock, dicevalue, p);
						}
					}
					int temparr[7];
					for (int i = 0; i < 7; i++)
					{
						temparr[i] = 0;
					}
					for (int i = 0; i < 7; i++)
					{
						if (lock[i] == true)
						{

							temparr[i] = dicevalue[i];
							totalp = totalp + userwins(temparr);
						}
					}
					if (totalp == 0)
					{
						turns += 1;
						cout << "You have been FARKLED!!" << endl;
						cout << "The number of turns taken are: " << turns << endl;
						break;
					}
				}
				turns += 1;
				cout << "THE POINTS YOU SCORED ARE:" << totalp << endl;
				cout << "The number of turns taken are: " << turns << endl;
			}
			else
			{
				cout << "YOU HAVE WON!!" << endl;
				break;
			}
		}

		else
		{
			cout << "You have been FARKLED" << endl;
			turns += 1;
			cout << "THE POINTS YOU SCORED ARE:" << 0 << endl;
			cout << "The number of turns taken are: " << turns << endl;
			break;
		}
	}
}


void Farkle::rolldice(int dicevalue[], bool lock[], int j)
{


	if (lock[j] == false)
	{
		dicevalue[j] = rand() % 6 + 1;
	}

}

void Farkle::locking(bool lock[], int lockvalue)
{
	if (lockvalue >= 1 and lockvalue < 7)
	{
		lock[lockvalue] = true;
	}
	else
	{
		cout << "Enter a value between 1 to 6 for locking" << endl;
	}

}

int Farkle::userwins(int dicevalue[])
{

	int score[7];
	for (int i = 0; i < 7; i++)
	{
		score[i] = 0;
	}
	for (int i = 1; i < 7; i++)
	{
		if (dicevalue[i] > 0)
		{
			score[dicevalue[i]] += 1;
		}
		else
		{
			continue;
		}
	}

	int points;
	points = 0;

	for (int i = 0; i < 7; i++)
	{
		if (score[i] < 3)
		{
			points = score[1] * 100;
			points = points + (score[5] * 50);
		}
	}
	for (int i = 0; i < 7; i++)
	{
		if (score[i] >= 3)
		{
			if (score[i] == 3)
			{
				points = points + (i * 100);
			}

			if (score[i] == 4)
			{
				points = points + 1000;
			}

			if (score[i] == 5)
			{
				points = points + 2000;
			}

			if (score[i] == 6)
			{
				points = points + 3000;
			}
		}
	}
	return points;
	cout << "your total points are==>" << points << endl;
}

void Farkle::printlock(bool lock[], int dicevalue[], int p)
{
	if (lock[p] == false)
	{
		cout << "NEW dicevalue," << p << "=" << dicevalue[p] << endl;
	}
	else
	{
		cout << "OLD dicevalue," << p << "=" << dicevalue[p] << endl;
	}
}
