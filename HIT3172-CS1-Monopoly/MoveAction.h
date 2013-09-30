/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

	**********************************************

	MoveAction

	Implements the Action class to perform a
	particular transaction within the game.
	MoveAction(s) changes the player's position
	within the game board;
*/

#ifndef _H_MOVEACTION
#define _H_MOVEACTION

#include "Action.h"
#include <string>

class MoveAction : public Action
{
private:
	int			_distance;
	std::string	_description;

public:
	MoveAction(int _aDist, std::string _aDesc);
	void perform(Player *_aPlayer);
};

#endif