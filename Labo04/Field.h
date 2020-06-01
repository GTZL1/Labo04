#pragma once
#include <vector>
#include <list>
#include <random>
#include <time.h>
#include <math.h>

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
	void addHumanoid(Humanoid*);
	void display();
	int nextTurn();
	template <typename U>
	Humanoid* findNearest(size_t, size_t);
	size_t getDistance(int, int, int, int);
	~Field();
};

template <typename U>
Humanoid* Field::findNearest(size_t x, size_t y)
{
	unsigned short minDistance = -1;
	Humanoid* nearest = nullptr;
	for (Humanoid* h : humanoids)
	{
		if (h->getLetter() == U::LETTER)
		{
			unsigned short newDistance = this->getDistance(x, h->getXPos(), y, h->getYPos());
			if (newDistance < minDistance)
			{
				minDistance = newDistance;
				nearest = h;
			}
		}
	}
	return nearest;
}
