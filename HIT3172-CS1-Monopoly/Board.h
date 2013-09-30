/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

	**********************************************

	Board - declaration

	Class to mimic areal-life game board which players 
	play on. Boad manages a collection of _Tile_ objects
	used within the game.
*/

#ifndef _H_BOARD
#define _H_BOARD

#include <vector>
#include <string>

#include "Tile.h"

class Board
{
public:
	Board(void);
	~Board(void);

	void	add_tile(Tile *_aTile);
	Tile	*tile_at(int _aIndex);
	Tile	*tile_named(std::string _aName);
	int		tile_count();

	Tile *operator[] (int _aIndex);
	Tile *operator[] (std::string _aName);	

private:
	std::vector<Tile *>	_tiles;
	
};

#endif