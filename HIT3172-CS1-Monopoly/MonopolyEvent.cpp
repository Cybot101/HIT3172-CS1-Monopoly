/**
	MonopolyEvent.cpp
*/
#include "MonopolyEvent.h"

#include <sstream>

MonopolyEvent::MonopolyEvent(
	Player *_aPlayer, 
	std::string _aDescription, 
	EventKind _aKind, void *_aOther)
{
	player = _aPlayer;
	description = _aDescription;
	kind = _aKind;
	other = _aOther;
}

std::string MonopolyEvent::str()
{
	std::ostringstream desc;
	desc << "Event: " << kind << " Message: " << description;
	return desc.str();
}