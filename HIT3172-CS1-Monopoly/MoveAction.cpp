#include "MoveAction.h"


MoveAction::MoveAction(int _aDist, std::string _aDesc)
{
	_distance = _aDist;
	_description = _aDesc;
}

void MoveAction::perform(Player *_aPlayer)
{
	if (_aPlayer != NULL)
		_aPlayer->move(_distance, _description);
}