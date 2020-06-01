#pragma once
#include "Action.h"
class ActionMoveRandom :
	public Action
{
public:
	ActionMoveRandom(Humanoid* hum) :Action(hum, 0, 0){}
	void execute(Field& f)
	{
		srand((unsigned)time(0));
		humanoid->setXPos((humanoid->getXPos()) + (rand() % 2));
		humanoid->setYPos((humanoid->getYPos()) + (rand() % 2));
	}
};

