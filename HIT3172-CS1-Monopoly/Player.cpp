/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

	**********************************************

	Player - Implementation


*/

#include "Player.h"

#include <sstream>

/**
	Creates a player object with a name.

	@param string Player name
*/
Player::Player(std::string _aName)
{
	_isOn = NULL;
	_name = _aName;
}


Player::~Player(void)
{

}

/**
	Performs player "move" operation.
	Rolls dice, leaves current tile (if allowed) and move across board.

	@param Dice* Dice object to roll
*/
void Player::move(Dice *_aDice)
{
	// Roll of the dice
	_aDice->roll();
	
	if (_isOn != NULL)			// Player is on a tile
	{
		_isOn->leave(this);
		_isOn->move(this, _aDice, _aDice->get_total_value());
	}
}

/**
	Places the player on a particular Tile by letting the tile know it has landed on it.
*/
void Player::place_on(Tile *_aTile)
{
	if (_aTile != NULL)
	{
		_isOn = _aTile;
		_isOn->land(this);
	}
}

/**
	Public getter for tile player is currently on.

	@return Tile* Tile player is currently on
*/
Tile *Player::on_tile()
{
	return _isOn;
}

std::string Player::str()
{
	std::stringstream desc;
	desc << _name << " - Current tile: " << _isOn << " ";

	return desc.str();
}