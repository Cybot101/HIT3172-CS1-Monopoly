/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

*/


#include "Die.h"
#include "Dice.h"
#include "Board.h"
#include "Player.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	// Iteration 3
	
	// Create a game Board
	Board *_board = new Board();

	const int _num_tiles = 15;

	std::string tiles[_num_tiles] = 
	{
		"GO",
		"Old Kent Road",
		"Comunity Chest 1",
		"Whitechapel Road",
		"Income Tax 1",
		"Railroad 1",
		"The Angel Islington",
		"Chance 1",
		"Euston Road",
		"Pentonville Road",
		"Jail",
		"Pall Mall",
		"Electricity",
		"Whitehall Road",
		"Northumberland Avenue"
	};

	// Create tiles
	for (int i=0; i < _num_tiles; i++)
	{
		_board->add_tile(new Tile(tiles[i]));
	}

	// Link last tile to first
	(*_board)[ _num_tiles-1 ]->set_next( (*_board)[0] );

	// Link all tiles
	for (int i=0; i<(_num_tiles-1); i++)
	{
		(*_board)[i]->set_next( (*_board)[i+1] );
	}

	
	Player * kyle = new Player("Kyle");
	Player * bob = new Player("Kyle");
	Dice * roller = new Dice();
	roller->add_die(new Die(6));
	roller->add_die(new Die(6));

	kyle->place_on( (Tile *)_board->tile_named("GO") );
	bob->place_on( (Tile *)_board->tile_named("GO") );

	
	/*for (int i=0; i < _board->tile_count() -1 ; i++)
	{
		std::cout << (_board->tile_at(i)->str()) << endl;
	}*/

	char key;

	do
	{
		cout << endl << "'r' to roll, 'q' to quit" << endl << "> ";
		std::cin >> key;
		switch (key)
		{
		case 'r':
			kyle->move(roller);
			cout << "Kyle's roll: " << roller->get_total_value() << endl;
			cout << (*kyle->on_tile()) << endl << endl;

			bob->move(roller);
			cout << "Bob's roll: " << roller->get_total_value() << endl;
			cout << (*bob->on_tile()) << endl;

			break;
		}


		/*for (int i=0; i < _board->tile_count() -1 ; i++)
		{
			std::cout << (_board->tile_at(i)->str()) << endl;
		}*/
	} while (key != 'q');


	delete _board, roller, kyle;
	
	//system("pause");

	return 0;
}