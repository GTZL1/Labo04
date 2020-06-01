#include "Humanoid.h"
#include "Action.h"
#include "ActionKill.h"
#include "ActionMoveRandom.h"
#include "ActionMoveTo.h"

using namespace std;

Humanoid::Humanoid()
{}

Humanoid::Humanoid(size_t x, size_t y)
{
	xPos = x;
	yPos = y;
}

bool Humanoid::isAlive()
{
	return alive;
}

size_t Humanoid::getXPos()
{
	return xPos;
}

size_t Humanoid::getYPos()
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
	//it's the only case with a nullptr at action execution
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

//char Humanoid::getLetter() const
//{
//	return this->LETTER;
//}

std::ostream & operator<<(std::ostream& os, Humanoid& h)
{
	os << h.toString();
	return os;
}
