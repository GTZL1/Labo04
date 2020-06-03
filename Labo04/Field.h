/* -------------------------------------------------------------------
 * File: Field.h
 *
 * Authors: David Dupraz, Soulaymane Lamrani, Alexandre Simik
 *
 * Content: header of Field class
 *
 * ------------------------------------------------------------------ */
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
	std::list<Humanoid*> humanoids; //pointers to all alive humanoids of the game
	size_t turn = 0;
	std::string firstAndBottomLine();

public:
	/*!
	 * Standard constructor
	 * 
	 * \param x size of field
	 * \param y size of field
	 */
	Field(size_t, size_t);

	/*!
	 * Populate field with given numbers of vampires and humans and Buffy at random positions
	 * 
	 * \param number of vampires
	 * \param number of humans
	 */
	void populate(size_t, size_t);

	/*!
	 * Add a Humanoid to the game
	 * 
	 * \param pointer to new Humanoid
	 */
	void addHumanoid(Humanoid*);

	/*!
	 * Erase properly content of humanoids and reset turn to 0
	 * 
	 */
	void clearContent();

	/*!
	 * Get x size of field
	 * 
	 * \return x size
	 */
	size_t getXSize();

	/*!
	 * Get y size of field
	 * 
	 * \return y size
	 */
	size_t getYSize();

	/*!
	 * Display current state of field
	 * 
	 */
	void display();

	/*!
	 * Run one turn of the game
	 * 
	 * \return current number turn
	 */
	size_t nextTurn();

	/*!
	 * Find nearest humanoid from a given position
	 * 
	 * \param x position
	 * \param y position
	 * \param U type of Humanoid to find: Human or Vampire
	 * \return ptr to nearest humanoid, nullptr if none
	 */
	template <typename U>
	Humanoid* findNearest(size_t, size_t);

	/*!
	 * int params are necessary because function uses abs()
	 * which cannot work with size_t
	 * 
	 * \param first x
	 * \param second x
	 * \param first y
	 * \param second y
	 * \return distance between the two points
	 */
	size_t getDistance(int, int, int, int);

	/*!
	 * Standard destructor
	 * 
	 */
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
