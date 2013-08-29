/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

*/

#include "Die.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	Die dice(11);

	int freq[12] = {0};
	double mean = 0;

	for (int i=0; i<100; i++)
	{
		dice.roll();
		
		freq[dice.get_top_value()]++;

		mean += dice.get_top_value();

		//cout << dice.get_top_value() << endl;
	}

	cout << "Dice roll frequency" << endl;

	

	for (int i=1; i<12; i++)
		cout << i << ":" << freq[i] << endl;

	cout << "Mean: " << mean/100 << " -> " << (int)(mean/100) << endl;

	return 0;
}