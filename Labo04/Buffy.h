#pragma once
#include "Humanoid.h"
class Vampire;

class Buffy : public Humanoid
{
	static const size_t HUNTING_RANGE = 2;
	static const char LETTER = 'B';
public:
	Buffy(size_t xPos, size_t yPos) :Humanoid(xPos, yPos) {}
	char getLetter() const;
	void setAction(Field&);
	void executeAction(Field&);
};

