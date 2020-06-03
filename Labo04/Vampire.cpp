/* -------------------------------------------------------------------
 * File: Vampire.cpp
 *
 * Authors: David Dupraz, Soulaymane Lamrani, Alexandre Simik
 *
 * Content: implementation of Vampire class
 *
 * ------------------------------------------------------------------ */
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
	
	Humanoid* nearest = f.findNearest<Human>(this->getXPos(), this->getYPos());

	if (nearest == nullptr)
	{
		action = nullptr;
	}
	else if (f.getDistance(this->getXPos(), nearest->getXPos(), this->getYPos(), nearest->getYPos())<=Vampire::HUNTING_RANGE)
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
