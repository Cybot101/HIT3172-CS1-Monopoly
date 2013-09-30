/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

	**********************************************

	Dice - Interface declaration

	Dice class to mimic a set of real-life
	dice.
	Class contains and handles interractions with Die objects.
*/

#ifndef _H_DICE
#define _H_DICE

#include <vector>
#include "Die.h"

class Dice
{
public:
	Dice(void);		// Constructor
	~Dice(void);	// Destructor - called when object is being destroyed.

	void	add_die(Die *_aDie);
	void	 roll(void);
	Die		*die_at(int _aIndex);

	int		get_total_value();
	bool	all_same();

private:
	std::vector<Die *>	_die;

};

#endif