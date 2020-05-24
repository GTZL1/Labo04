#pragma once

#include "Humanoid.h"

class Action
{
	Humanoid* humanoid;
public:
	Action(Humanoid* hum) :humanoid(hum) {}
	virtual void execute() = 0;
};

