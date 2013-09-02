#include "Board.h"

Board::Board(void)
{

}


Board::~Board(void)
{
	// Delete all Tiles in collection
	for (int i=0; i<_tiles.size(); i++)
	{
		delete _tiles[i];
	}
	_tiles.clear();
}

/**
	Adds new tile to colelction.

	@param Tile* New tile to add to collection
*/
void Board::add_tile(Tile *_aTile)
{
	if (_aTile != NULL)
		_tiles.push_back(_aTile);
}

/**
	Returns Tile at position _index_ within tile collection.

	@param int Index of Tile
	@return Tile* Tile at supplied index
*/
Tile *Board::tile_at(int _aIndex)
{
	if (_aIndex >= 0 && _aIndex <= (_tiles.size()-1))
		return (Tile*)_tiles[_aIndex];
	else
		return NULL;
}

/**
	Return Tile in collectiong with the name specified.

	@param string Name of tile to find
	@return Tile Tile found with given name
*/
Tile* Board::tile_named(std::string _aName)
{
	for (int i=0; i<_tiles.size(); i++)		//Could we use an indexed list/hash table for this??
	{
		if (_tiles[i]->get_name() == _aName)
			return (Tile *)_tiles[i];
	}

	// No match found.
	return NULL;
}

/**
	Public access property for number of Tiles this Board has.

	@return int Number of Tiles within colelction
*/
int Board::tile_count(void)
{
	return _tiles.size();
}

Tile * Board::operator[] (int _aIndex)
{
	return tile_at(_aIndex);
}

Tile * Board::operator[] (std::string _aName)
{
	return tile_named(_aName);
}