#pragma once
#include <vector>
#include <list>
#include <random>
#include <time.h>

#include "Humanoid.h"

class Field
{
	const char delimiterVertical = '|';
	const char delimiterHorizontal = '_';
	const char edgeChar = '*';
	size_t xSize, ySize;
	std::list<Humanoid*> humanoids;
	size_t turn = 0;
	std::string firstAndBottomLine();

public:
	Field(size_t, size_t);
	void populate(size_t, size_t);
	void display();
	int nextTurn();
	template <typename U>
	U* findNearest(size_t, size_t);
	size_t getDistance(size_t, size_t, size_t, size_t);
	~Field();
};
