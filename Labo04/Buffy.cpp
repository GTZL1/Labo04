#include "Buffy.h"
#include "Vampire.h"
#include "Action.h"
#include "ActionKill.h"
#include "ActionMoveRandom.h"
#include "ActionMoveTo.h"

char Buffy::getLetter() const
{
	return Buffy::LETTER;
}

void Buffy::setAction(Field& f)
{
	Humanoid::setAction(f);

	Humanoid* nearest = f.findNearest<Vampire>(this->xPos, this->yPos);

	if (nearest == nullptr)
	{
		action = new ActionMoveRandom(this);
	}
	else if (f.getDistance(xPos, nearest->getXPos(), yPos, nearest->getYPos()) <= Buffy::HUNTING_RANGE)
	{
		action = new ActionKill(nearest);
	}
	else
	{
		action = new ActionMoveTo(this, nearest->getXPos(), nearest->getYPos());
	}
}

void Buffy::executeAction(Field& f)
{
	Humanoid::executeAction(f);
	Humanoid::executeAction(f);
}
