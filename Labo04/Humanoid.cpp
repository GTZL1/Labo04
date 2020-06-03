#include "Humanoid.h"
#include "Action.h"
#include "ActionKill.h"
#include "ActionMoveRandom.h"
#include "ActionMoveTo.h"

using namespace std;

Humanoid::Humanoid(size_t x, size_t y)
{
	xPos = x;
	yPos = y;
}

bool Humanoid::isAlive() const
{
	return alive;
}

size_t Humanoid::getXPos() const
{
	return xPos;
}

size_t Humanoid::getYPos() const
{
	return yPos;
}

void Humanoid::setXPos(size_t x)
{
	xPos = x;
}

void Humanoid::setYPos(size_t y)
{
	yPos = y;
}

void Humanoid::setAction(Field& f)
{
	delete action;
}

void Humanoid::executeAction(Field& f)
{
	//when a new Vampire is created from an human, it doesn't have an action
	//also when there are no more humans, vampires don't move anymore
	if (action != nullptr)
	{
		action->execute(f);
	}
}

void Humanoid::killIt()
{
	this->alive = false;
}

std::string Humanoid::toString() const
{
	return string(1, getLetter());
}

Humanoid::~Humanoid()
{
	delete action;
}

std::ostream & operator<<(std::ostream& os, Humanoid& h)
{
	os << h.toString();
	return os;
}
