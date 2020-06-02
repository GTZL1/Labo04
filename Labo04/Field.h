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
	const char delimiterHorizontal = '-';
	const char edgeChar = '*';

	size_t xSize, ySize;
	std::list<Humanoid*> humanoids;
	size_t turn = 0;
	std::string firstAndBottomLine();

public:
	Field(size_t, size_t);
	void populate(size_t, size_t);
	void addHumanoid(Humanoid*);
	void clearContent();
	size_t getXSize();
	size_t getYSize();
	void display();
	size_t nextTurn();
	template <typename U>
	Humanoid* findNearest(size_t, size_t);

	/*!
	 * 
	 * int params are necessary because function uses abs()
	 * which cannot work with size_t
	 * 
	 * \param 
	 * \param 
	 * \param 
	 * \param 
	 * \return 
	 */
	size_t getDistance(int, int, int, int);
	~Field();
};

template <typename U>
Humanoid* Field::findNearest(size_t x, size_t y)
{
	size_t minDistance = -1;
	Humanoid* nearest = nullptr;
	for (Humanoid* h : humanoids)
	{
		if (h->getLetter() == U::LETTER)
		{
			size_t newDistance = this->getDistance(x, h->getXPos(), y, h->getYPos());
			if (newDistance < minDistance)
			{
				minDistance = newDistance;
				nearest = h;
			}
		}
	}
	return nearest;
}
