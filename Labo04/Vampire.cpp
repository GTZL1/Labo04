#include "Vampire.h"
#include "Human.h"
#include "Action.h"
#include "ActionKill.h"
#include "ActionMoveTo.h"
#include "ActionNewVampire.h"

void Vampire::setAction(Field& f)
{
	srand((unsigned)time(0));
	Humanoid::setAction(f);
	
	Humanoid* nearest = f.findNearest<Human>(this->xPos, this->yPos);

	if (nearest == nullptr)
	{
		action = nullptr;
	}
	else if (f.getDistance(xPos, nearest->getXPos(), yPos, nearest->getYPos())<=Vampire::HUNTING_RANGE)
	{
		if (rand() % 2)
		{
			action = new ActionKill(nearest);
		}
		else
		{
			action = new ActionNewVampire(nearest);
		}
	}
	else
	{
		action = new ActionMoveTo(this, nearest->getXPos(), nearest->getYPos());
	}
}

char Vampire::getLetter() const
{
	return Vampire::LETTER;
}
