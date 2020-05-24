#pragma once
#include "Humanoid.h"
class Buffy : public Humanoid
{
	static const size_t HUNTING_RANGE;
public:
	Buffy(size_t xPos, size_t yPos) :Humanoid(xPos, yPos, 'B') {}
};

