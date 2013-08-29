#include "Die.h"

#include <stdlib.h>

/**
	Constructor - builds the Die object

	@param	aSides	Number of sides for die
*/
Die::Die(int aSides)
{
	_sides = aSides;
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