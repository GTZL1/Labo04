#pragma once
#include "Action.h"
class ActionMoveTo :
	public Action
{
public:
	ActionMoveTo(Humanoid* hum, size_t xTo, size_t yTo) :Action(hum, xTo, yTo){}

	void execute(Field& f)
	{
		if (xTo < humanoid->getXPos())
		{
			humanoid->setXPos(humanoid->getXPos() - 1);
			if (yTo < humanoid->getYPos())
			{
				humanoid->setYPos(humanoid->getYPos() - 1);
			}
			else if (yTo > humanoid->getYPos())
			{
				humanoid->setYPos(humanoid->getYPos() + 1);
			}
		}
		else if (xTo > humanoid->getXPos())
		{
			humanoid->setXPos(humanoid->getXPos() + 1);
			if (yTo < humanoid->getYPos())
			{
				humanoid->setYPos(humanoid->getYPos() - 1);
			}
			else if (yTo > humanoid->getYPos())
			{
				humanoid->setYPos(humanoid->getYPos() + 1);
			}
		}
		else
		{
			if (yTo < humanoid->getYPos())
			{
				humanoid->setYPos(humanoid->getYPos() - 1);
			}
			else if (yTo > humanoid->getYPos())
			{
				humanoid->setYPos(humanoid->getYPos() + 1);
			}
		}
	}
};

