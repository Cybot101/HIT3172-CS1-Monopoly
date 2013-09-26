/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

	**********************************************

	TransAction

	Implements the Action class to perform a
	particular transaction within the game.
	TransAction(s) alter amount of cash the player
	has.

*/
#ifndef _H_TRANSACTION
#define _H_TRANSACTION

#include "Action.h"
#include <string>

class TransAction :	public Action
{
private:
	int			_value;
	std::string	_description;

public:
	TransAction(int _aVal, std::string _aDesc);
	void perform(Player *);
};

#endif