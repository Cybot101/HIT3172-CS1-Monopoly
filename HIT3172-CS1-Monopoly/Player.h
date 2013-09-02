/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

	**********************************************

	Player - Interface declaration

*/

#ifndef _H_PLAYER
#define _H_PLAYER

#include "Tile.h"
#include "Dice.h"

#include <string>

class Player
{
public:

	Player(std::string _aName);
	~Player(void);

	void	move(Dice *_aDice);
	void	place_on(Tile *_aTile);

	std::string		str();

	Tile	*on_tile();		// Getter for tile player is on

	std::ostream operator<<(std::ostream& out);

private:
	Tile*		_isOn;
	std::string	_name;

};

#endif