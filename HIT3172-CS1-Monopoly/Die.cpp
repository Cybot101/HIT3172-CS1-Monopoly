/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

	**********************************************

	Die - Implementation

	Die class to mimic a real-life dice (die) for use 
	within the Monopoly game.
*/


#include "Die.h"

#include <stdlib.h>
#include <time.h>

/**
	Constructor - builds the Die object

	@param	aSides	Number of sides for die
*/
Die::Die(int aSides)
{
	_sides = aSides;

	// Init random generator with a random seed (based on current time)
	srand(time(NULL));
}


// Destructor
// Die, die...
Die::~Die(void)
{}

/**
	Rolls die using random number generator
*/
void Die::roll()
{
	_top_value = (int)( rand() % _sides + 1 );
}

/**
	Public access property getter.

	Returns value of private _sides field.
*/
int Die::get_sides()
{
	return _sides;
}

/**
	Public access property getter.

	Returns value of private _top_value field.
*/
int Die::get_top_value()
{
	return _top_value;
}