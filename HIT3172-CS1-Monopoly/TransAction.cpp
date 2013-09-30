/**
	TransAction.cpp
*/
#include "TransAction.h"

TransAction::TransAction(int _aVal, std::string _aDesc)
{
	_description = _aDesc;
	_value = _aVal;
}

void TransAction::perform(Player *_aPlayer)
{
	if (_aPlayer != NULL)
	{
		_aPlayer->change_cash(_value, _description);
	}
}