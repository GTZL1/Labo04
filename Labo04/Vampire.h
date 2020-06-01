#pragma once
#include <random>
#include "Humanoid.h"
#include "Field.h"

class Human;

class Vampire :	public Humanoid
{
	static const size_t HUNTING_RANGE=1;
	
public:
	static const char LETTER = 'V';
	Vampire(size_t xPos, size_t yPos) :Humanoid(xPos, yPos) {}
	void setAction(Field&);
	char getLetter() const;
};
