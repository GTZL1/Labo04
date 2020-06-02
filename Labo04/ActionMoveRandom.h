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
		if (rand() % 2)
		{
			humanoid->setXPos((humanoid->getXPos()) + 1);
			humanoid->setYPos((humanoid->getYPos()) +1);
		}
		else
		{
			humanoid->setXPos((humanoid->getXPos()) - 1);
			humanoid->setYPos((humanoid->getYPos()) - 1);
		}

		if (humanoid->getXPos() >= f.getXSize())
		{
			humanoid->setXPos(f.getXSize() - 1);
		}
		if (humanoid->getYPos() < 1)
		{
			humanoid->setYPos(1);
		}
		else if (humanoid->getYPos() >= f.getYSize())
		{
			humanoid->setYPos(f.getYSize() - 1);
		}
	}
};

