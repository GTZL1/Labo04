#pragma once
#include "Humanoid.h"
class Human : public Humanoid
{
public:
	Human():Humanoid('h'){}
	Human(size_t xPos, size_t yPos) :Humanoid(xPos, yPos, 'h'){}
};

