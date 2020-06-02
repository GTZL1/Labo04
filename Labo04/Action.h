#pragma once
#include <time.h>
#include "Humanoid.h"
#include "Field.h"

class Action
{
protected:
	Humanoid* humanoid;
	size_t xTo, yTo;
public:
	Action(Humanoid* hum, size_t x, size_t y) :humanoid(hum), xTo(x), yTo(y) {}
	virtual void execute(Field& f) = 0;
	virtual ~Action(){}
};

