/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

	**********************************************

	Tile - Implementation

*/

#include "Tile.h"

#include <sstream>
#include "Player.h"

/**
	Constructor. Initialise colelction of players and set Tile object's
	name and attributes.

	@param string Name of tile
	@param Tile* Next tile to be linked to
*/
Tile::Tile(std::string _aName)
{
	_players = std::vector<Player *>();

	_name = _aName;
	_next = NULL;
}

/**
	Destructor. Cleans up
*/
Tile::~Tile(void)
{
	// Delete all Players in collection
	for (unsigned int i=0; i<_players.size(); i++)
	{
		delete _players[i];
	}
	_players.clear();
}

/**
	Moves player onto next tile, given the number of spaces rolled on the Dice.

	@param Player* Player to move
	@param Dice* Dice obejct
	@param int Number of 'moves' remaining.
*/
void Tile::move(Player *_aPlayer, Dice *_aDice, int _aRemaining)
{
	if (_aPlayer != NULL)
	{
		if (_aRemaining > 0)
			_next->move(_aPlayer, _aDice, --_aRemaining);
		else
			_aPlayer->place_on(this);
	}
}

/**
	Function to "land" the player on this tile.
	Will update this tile's player reference to indicate a landing.
	
	@param Player* Player object to land on this tile
*/
void Tile::land(Player *_aPlayer)
{
	if (_aPlayer != NULL)
		_players.push_back(_aPlayer);
}

/**
	Function for when players "leave" this tile.
	Will update this tile's player reference to indicate the player has left.

	@param Player Player to leave current tile
*/
void Tile::leave(Player *_aPlayer)
{
	for (unsigned int i=0; i<_players.size(); i++)
		if (_players[i] == _aPlayer)					// Better way to do this?? 
			_players.erase(_players.begin() + i);		//http://stackoverflow.com/questions/4442477/remove-ith-item-from-c-stdvector
}

/**
	Public access getter to retrieve the Tile's name.

	@return string Name of tile
*/
std::string Tile::get_name()
{
	return _name;
}

/**
	Public access getter to retrieve the next Tile.

	@return Tile* Next tile in sequence
*/
Tile *Tile::get_next()
{
	return _next;
}

/**
	Public access setter to set the next Tile.

	@param Tile* Next tile in sequence
*/
void Tile::set_next(Tile *_aTile)
{
	_next = _aTile;
}

/**
	Returns name (and description) of Tile in a human-readable format.

	@return string Tile name and description
*/
std::string Tile::str()
{
	std::ostringstream desc;
	desc << _name << " ( " << _players.size() << " players ) ";

	return desc.str();
}

/**
	Overload for stream opperator. Enables Tile object to be "printed" out easily.
*/
std::ostream& operator<< (std::ostream& out, Tile& tile)
{
	out << (tile.str());
	return out;
}