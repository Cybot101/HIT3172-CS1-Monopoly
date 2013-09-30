/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

	**********************************************

	Action

	Completely abstract method to interface Action
	actions. Actions are performed withing the 
	Monopoly game to alter the game's state.
*/

#ifndef _H_ACTION
#define _H_ACTION

#include "Player.h"

class Action
{
public:
	virtual void perform(Player *) = 0;
};

#endif