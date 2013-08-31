/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

*/


#include "Die.h"
#include "Dice.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	Dice *_dice = new Dice();

	_dice->add_die(new Die(6));
	_dice->add_die(new Die(6));

	for (int i=0; i<10; i++)
	{
		// Roll all the dice
		_dice->roll();

		// Print each value
		cout << "Die 1 = " << _dice->die_at(0)->get_top_value() << endl;
		cout << "Die 2 = " << _dice->die_at(1)->get_top_value() << endl;

		// Print total value
		cout << "Total = " << _dice->get_total_value() << endl << endl;

	}

	system("pause");

	return 0;
}