/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	@version	1.1 Changes for iteration 4

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

	**********************************************

	Player - Implementation


*/

#include "Player.h"
#include "MonopolyGame.h"

#include <sstream>

/**
	Creates a player object with a name.

	@param string Player name
*/
Player::Player(std::string _aName, MonopolyGame *_aGame)
{
	_isOn = NULL;
	_name = _aName;
	_playing = _aGame;
	_cash = 500;
}


Player::~Player(void)
{
}

/**
	Places the player on a particular Tile by letting the tile know it 
	has landed on it.
*/
void Player::place_on(Tile *_aTile)
{
	if (_aTile != NULL)
	{
		_isOn = _aTile;
		_isOn->land(this);

		_playing->anounce_monopoly_event( MonopolyEvent(this, "Player landed on tile: " + _aTile->str(), EventKind::LAND_EVENT, _aTile) );
	}
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
	
	_playing->anounce_monopoly_event(MonopolyEvent(this, "Player rolled dice", EventKind::DICE_EVENT, _aDice) );
	
	if (_isOn != NULL)			// Player is on a tile
	{
		_isOn->leave(this);
		_isOn->move(this, _aDice, _aDice->get_total_value());

		_playing->anounce_monopoly_event(MonopolyEvent(this, "Player moved", EventKind::MOVE_EVENT, _aDice) );
	}
}

/**
	Moves the player a number of spaces along the game board.
	Used by the MoveAction.

	@param int Distance to move
	@param string Description of action
*/
void Player::move(int _aDist, std::string _aDesc)
{
	if (_isOn != NULL)			// Player is on a tile
	{
		_isOn->leave(this);
		_isOn->move(this, NULL, _aDist);

		_playing->anounce_monopoly_event(MonopolyEvent(this, "Player moved", EventKind::MOVE_EVENT, NULL) );
	}
}

/**
	Changes the amount of cash the player has.

	@param int Cash amount of change by
	@param string Description of action
*/
void Player::change_cash(int _aDeltaCash, std::string _aDesc)
{
	_cash += _aDeltaCash;

	_playing->anounce_monopoly_event( MonopolyEvent(this, "Player transferred cash", EventKind::TRANSATION_EVENT, NULL) );
}

/**
	Public getter for tile player is currently on.

	@return Tile* Tile player is currently on
*/
/*Tile *Player::on_tile()
{
	return _isOn;
}*/

std::string Player::str()
{
	std::stringstream desc;
	desc << _name;

	return desc.str();
}

/**
	Public getter for amount of cash the player has.

	@return int Amount of cash player has
*/
int Player::cash()
{
	return _cash;
}