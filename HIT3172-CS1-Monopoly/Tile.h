/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

	**********************************************

	Tile - Interface declaration

	A tile within a Board object. 
	Tiles are "played on" by the Players.

*/

#ifndef _H_TILE
#define _H_TILE

#include <string>
#include <vector>

#include "Dice.h"
//#include "Player.h"

// Possible forward dependancy error?
// http://stackoverflow.com/questions/4018816/circular-dependency-in-c
class Player;

class Tile
{
public:
	Tile(std::string _aName);
	~Tile(void);

	void	move(Player *_aPlayer, Dice *_aDice, int _aRemaining);
	void	land(Player *_aPlayer);
	void	leave(Player *_aPlayer);

	Tile			*get_next();
	void			set_next(Tile *_aTile);		// Public setter to set next tile.
	std::string		str();
	std::string		get_name();

	


private:
	Tile					*_next;
	std::vector<Player *>	_players;
	std::string				_name;

	
};

// Overlaod the stream operator to make printing name easier
	std::ostream& operator <<(std::ostream& out, Tile& tile);

#endif