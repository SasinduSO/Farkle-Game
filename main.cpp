#include <iostream>
#include <cstring>
#include <string>
#include "Farkle.h"

using namespace std;

int main()
{
	Farkle F1;
	int opt = F1.runMenu();
	switch (opt)
	{
	case 1: {
		cout << "You have selected :" << opt << endl;
		F1.displayRules();
	}
		  break;
	case 2: {
		cout << "You have selected :" << opt << endl;
		F1.displayfunction();
	}
		  break;
	case 3:
	{
		cout << "You have selected :" << opt << endl;
		bool lock[7] = { false };
		int dicevalue[7];
		cout << endl;
		cout << "Select difficulty level (1-3):" << endl;
		cout << "(1) Rookie" << endl;
		cout << "(1) Roller" << endl;
		cout << "(1) High Roller" << endl;
		int level;
		cin >> level;
		int max = 0;
		switch (level)
		{
		case 1:
		{
			max = 5000;
			cout << endl;
			cout << "Your targer score is set to:" << max << endl;
			F1.playFarkle(lock, dicevalue, max);
		}
		break;

		case 2:
		{
			max = 10000;
			cout << endl;
			cout << "Your targer score is set to:" << max << endl;
			F1.playFarkle(lock, dicevalue, max);
		}
		break;
		case 3:
		{
			max = 15000;
			cout << endl;
			cout << "Your targer score is set to:" << max << endl;
			F1.playFarkle(lock, dicevalue, max);

		}
		break;
		}
	}
	break;
	}


	cout << "Do you want to select again?" << endl;
	cout << "~press Y for yes and any key for no..~" << endl;
	char ch;
	cin >> ch;


	if (ch == 'y')  //looping to use program as often as they want
	{
		main();
		int farks = 0;
		farks += 1;
		if (farks > 3)
		{
			ch = 'p';
		}
	}
}
