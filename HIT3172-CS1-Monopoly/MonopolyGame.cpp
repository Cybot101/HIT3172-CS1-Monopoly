/**
	MonopolyGame.cpp
*/
#include "MonopolyGame.h"

#include "TransAction.h"
#include "MoveAction.h"
#include <fstream>
#include <string>
#include <iostream>

/**
	Create MonopolyGame object and initialise fields.
	Initialises game board and dice, and sets-up actions.
*/
MonopolyGame::MonopolyGame(void)
{
	create_board();
	create_dice();
	setup_board_actions();

	_players = std::vector<Player *>();
	_current_player_idx = 0;
}

/**
	Destructor - cleans up player and action collections
*/
MonopolyGame::~MonopolyGame(void)
{
	for (int i=0; i<_players.size(); i++)
		delete _players[i];

	for (int i=0; i<_actions.size(); i++)
		delete _actions[i];
}

/**
	Created monopoly board by creating tiles from a file
	list. Links tiles together.
*/
void MonopolyGame::create_board()
{
	_board = new Board();

	int _num_tiles;
	int i=0;

	/* ToDo: Add tiles from file */
	//Setup tiles
	std::ifstream tileFile("tiles.txt");
	std::string tileString;

	while (std::getline(tileFile, tileString))
	{
		//std::cout << tileString << endl;
		_board->add_tile( new Tile(tileString) );
		i++;
	}
	tileFile.close();

	_num_tiles = i;

	// Link last tile to first
	(*_board)[ _num_tiles-1 ]->set_next( (*_board)[0] );

	// Link all tiles
	for (int i=0; i<(_num_tiles-1); i++)
	{
		(*_board)[i]->set_next( (*_board)[i+1] );
	}
}

/**
	Creates dice and adds two six-sided  dies to it.
*/
void MonopolyGame::create_dice()
{
	_dice = new Dice();
	_dice->add_die(new Die(6));
	_dice->add_die(new Die(6));
}

/**
	Loads actions from file
	[
		tile name
		action name
		land/pass	0=land, 1=pass
		type		0=trans, 1=move
		value		int amount
	]
*/
void MonopolyGame::setup_board_actions()
{
	_actions = std::vector<Action *>();
	//_actions.push_back( (Action*)new TransAction(200, "Steals money from the player") );
	//_actions.push_back( (Action*)new MoveAction(2, "Throws player around") );


	std::ifstream actionFile("actions.txt");
	std::string actionString;

	while ( actionFile.good() )
	{
		std::string data[5];
		// Read 5 lines from file
		for (int i=0; i<5 && std::getline(actionFile, actionString); i++)
		{
			std::cout << actionString << std::endl;
			data[i] = actionString;
		}
		
		Action * newAction;

		if (atoi(data[3].c_str()) == 0)
		{
			newAction = new TransAction( 
				atoi(data[4].c_str()) , data[1]);
		}
		else
		{
			newAction = new MoveAction( 
				atoi(data[4].c_str()) , data[1]);
		}
		
		if (atoi(data[2].c_str()) == 0)
		{
			_board->tile_named( data[0] )->set_land_action(newAction);
		}
		else
		{
			_board->tile_named( data[0] )->set_pass_action(newAction);
		}

		_actions.push_back(newAction);
	}
	actionFile.close();
}

/**
	Public access for current player.

	@return Player* Current player
*/
Player *MonopolyGame::current_player()
{
	return _players[_current_player_idx];
}
/**
	Returns number of players in the game.

	@return int Number of players
*/
int MonopolyGame::player_count()
{
	return _players.size();
}

/**
	Public access to Dice object.

	@return Dice* Dice object in game
*/
Dice *MonopolyGame::get_dice()
{
	return _dice;
}

Board *MonopolyGame::get_board()
{
	return _board;
}

/**
	Public access to Board object.

	@return Board* Board object in game
*/
void MonopolyGame::add_player(Player *_aPlayer)
{
	_players.push_back(_aPlayer);
	_aPlayer->place_on( _board->tile_at(0) );
}

/**
	Retrieves player at specified index within the player 
	collection.

	@return Player* Player at specified index
*/
Player *MonopolyGame::player_at(int _aIndex)
{
	if (_aIndex >= 0 && _aIndex < _players.size())
		return _players[_aIndex];
	else
		return NULL;
}

void MonopolyGame::perform_move()
{
	//Move player.
	// if player rolls same number, they get a second turn
	_players[_current_player_idx]->move(_dice);

	if ( !_dice->all_same() )
		_current_player_idx++;
	if (_current_player_idx > _players.size()-1)
		_current_player_idx = 0;
}

void MonopolyGame::anounce_monopoly_event(MonopolyEvent e)
{
	// Print to console
	std::cout << e.str() << std::endl;
}