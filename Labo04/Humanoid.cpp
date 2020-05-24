#include "Humanoid.h"

using namespace std;

Humanoid::Humanoid(char letter):letter(letter)
{}

Humanoid::Humanoid(size_t x, size_t y, char letter):Humanoid(letter)
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

void Humanoid::setAction(Field& f)
{
	delete action;
}

std::string Humanoid::toString() const
{
	return string(1, letter);
}

std::ostream & operator<<(std::ostream& os, Humanoid& h)
{
	os << h.toString();
	return os;
}
