#pragma once
#include "Humanoid.h"
#include "Field.h"
class Human;

class Vampire :	public Humanoid
{
	static const size_t HUNTING_RANGE;
public:
	Vampire(size_t xPos, size_t yPos) :Humanoid(xPos, yPos, 'V') {}
	void setAction(Field&);
};
