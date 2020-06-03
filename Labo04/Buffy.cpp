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

	Humanoid* nearest = f.findNearest<Vampire>(this->getXPos(), this->getYPos());

	if (nearest == nullptr)
	{
		action = new ActionMoveRandom(this);
	}
	else if (f.getDistance(this->getXPos(), nearest->getXPos(), this->getYPos(), nearest->getYPos()) <= Buffy::HUNTING_RANGE)
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
	//a move action is executed twice, so Buffy moves forward 2 squares
	Humanoid::executeAction(f);
	Humanoid::executeAction(f);
}
