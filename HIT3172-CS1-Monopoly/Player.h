/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	@version	1.1 Changes for iteration 4

	http://github.com/Cybot101/HIT3172-CS1-Monopoly

	**********************************************

	Player - declaration
*/

#ifndef _H_PLAYER
#define _H_PLAYER

#include "Tile.h"
#include "Dice.h"

#include <string>

class MonopolyGame;

class Player
{
public:

	Player(std::string _aName, MonopolyGame *_aGame);
	~Player(void);

	void	place_on(Tile *_aTile);
	void	move(Dice *_aDice);
	void	move(int _aDist, std::string _aDesc);		// new event methods
	void	change_cash(int _aDeltaCash, std::string _aDesc);	//

	std::string		str();
	int				cash();	//Public getter for player's cash value

	//Tile	*on_tile();		// Getter for tile player is on

	std::ostream operator<<(std::ostream& out);

private:
	Tile			*_isOn;
	std::string		_name;
	MonopolyGame	*_playing;
	int				_cash;

};

#endif