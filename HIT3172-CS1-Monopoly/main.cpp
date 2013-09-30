/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/HIT3172-CS1-Monopoly
*/

#include "MonopolyGame.h"
#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{
	// Iteration 4
	
	cout << "#   HIT3172  -  Object Orientated C++    #" << endl;
	cout << "#   Monopoly                             #" << endl;
	cout << "#  Kyle Harris   9621121                 #" << endl << endl;

	MonopolyGame *game = new MonopolyGame();

	cout << "# How many players are there?" << endl << "> ";
	int playerNum = 0;
	string name, name2;
	cin >> playerNum;

	if (playerNum > 0)
	{
		for (int i=0; i<playerNum; i++)
		{
			cout << "# Player " << (i+1) << "'s name?" << endl << "> ";
			cin >> name;

			Player * player = new Player(name, game);
			game->add_player(player);
		}
	

		char key;

		do
		{
			cout << "Player: " << game->current_player()->str();
			cout << endl << "'r' to roll, 'q' to quit" << endl << "> ";
			std::cin >> key;
			switch (key)
			{
			case 'r':
				game->perform_move();	// Rolls for current player
				//cout << "Roll : " << game->get_dice()->die_at(0)->get_top_value() << " + " <<
				//	game->get_dice()->die_at(1)->get_top_value() << endl << endl;	// Assuming 2 dies
				break;
			}

		} while (key != 'q');
	}

	delete game;

	return 0;
}

/**
	Helper function to print pretty player info to console
*/
void print_player(Player *_p)
{
	//int cash = _p->cash();

}