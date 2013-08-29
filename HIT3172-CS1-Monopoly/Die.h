/*
	HIT3172 - Object Orientated Programming C++

	Case Study 1 :: Monopoly

	Kyle Harris		9621121

	http://github.com/Cybot101/

	**********************************************

	Die - Interface declaration

	Die class to mimic a real-life dice (die) for use 
	within the Monopoly game.

*/

#ifndef _H_DIE
#define _H_DIE

class Die
{

public:
	
	// Constructor
	Die(int aSides);

	//Destructor
	~Die(void);

	int		get_top_value();
	int		get_sides();

	void	roll();

private:

	int		_sides;
	int		_top_value;
};

#endif