/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

	**********************************************

	Monopoly Event

	An event class to allow messaging of events to be
	passed around the monopoly game. MonopolyEvent 
	contains information about the player, event type
	and a descripter.
	
	Make class public access?? All methods and fields
	public?
*/

#ifndef _H_MONOPOLYEVENT
#define _H_MONOPOLYEVENT

#include "Player.h"

enum EventKind 
{
	DICE_EVENT,
	PASS_EVENT,
	LAND_EVENT,
	MOVE_EVENT,
	TRANSATION_EVENT
};

class MonopolyEvent
{
public:

	MonopolyEvent(Player *player, std::string description, EventKind kind, void *other);

	Player		*player;
	std::string	description;
	EventKind	kind;
	void		*other;

	std::string str();	//toString method
};

std::ostream& operator<< (std::ostream, MonopolyEvent *event);

#endif