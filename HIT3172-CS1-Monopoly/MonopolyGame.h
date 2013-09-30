/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

	**********************************************

	Monopoly Game

	Class to implement the main monopoly game 
	enviroment. Handles game actions and events.
*/
#ifndef _H_MONOPOLYGAME
#define _H_MONOPOLYGAME

#include "Player.h"
#include "Dice.h"
#include "Board.h"
#include "MonopolyEvent.h"
#include <vector>

class MonopolyGame
{

private:
	Board				*_board;
	Dice				*_dice;
	std::vector<Player *>	_players;
	int					_current_player_idx;
	std::vector<Action *>	_actions;

	void				create_board();
	void				create_dice();
	void				setup_board_actions();

public:
	MonopolyGame(void);
	~MonopolyGame(void);

	Player		*current_player();
	int			player_count();
	Dice		*get_dice();
	Board		*get_board();

	void		add_player(Player *_aPlayer);
	Player		*player_at(int _aIndex);
	void		perform_move();
	void		anounce_monopoly_event(MonopolyEvent e);
};

#endif