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

#include "Dice.h"

/**
	Construcotr.
	Create an empty collection of Die objects.
*/
Dice::Dice(void)
{
	// Create empty collection of Die objects
	_die = std::vector<Die *>();
}

/**
	Destructor.
	Destroys and cleans up Die objects.
*/
Dice::~Dice(void)
{
	for (int i=0; i<_die.size(); i++)
	{
		delete _die[i];
	}
	_die.clear();
}

/**
	Adds a Die object to the Dice collection.
	
	@param Die* Die object to add to Dice collection
*/
void Dice::add_die(Die *_aDie)
{
	_die.push_back(_aDie);
}

/**
	Rolls all dice.
*/
void Dice::roll()
{
	for (int i=0; i<_die.size(); i++)
	{
		_die[i]->roll();
	}
}

/**
	Returns Die object at a particular index within the Dice collection.
	Returns NULL if index outside of range.

	@param int Index of Die to check
	@return Die* Die object at position, or NULL if no Die.
*/
Die *Dice::die_at(int _aIndex)
{
	if (_aIndex >= 0 && _aIndex <= (_die.size()-1))
		return _die[_aIndex];
	else
		return NULL;	// Could throw an exception here (or is this not covered yet??)
}

/**
	Returns total value of current face of all Dice in colelction.

	@return int Total face value of all dice.
*/
int Dice::get_total_value()
{
	int tot = 0;
	for (int i=0; i<_die.size(); i++)
		tot += _die[i]->get_top_value();

	return tot;		// Could check for dice first, and report -1 if no dice are loaded.
}

/**
	Returns true if all dice have the same face-up value, false otherwise.

	@return bool True if same face-up value, false otherwise.
*/
bool Dice::all_same()
{
	if (_die.size() > 2)
	{
		bool same = true;

		for (int i=0; i<_die.size(); i++)
		{
			if (_die[0]->get_top_value() != _die[i]->get_top_value())
			{
				same = false;
				break;
			}
		}
			
		return same;
	}
	else
		return true;
}