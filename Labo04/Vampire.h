/* -------------------------------------------------------------------
 * File: Vampire.h
 *
 * Authors: David Dupraz, Soulaymane Lamrani, Alexandre Simik
 *
 * Content: header of Vampire class
 *
 * ------------------------------------------------------------------ */
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

	/*!
	 * Standard constructor
	 *
	 * \param xPos x start position
	 * \param yPos y start position
	 */
	Vampire(size_t xPos, size_t yPos) :Humanoid(xPos, yPos) {}

	/*!
	 * Get class symbol
	 *
	 * \return class symbol letter
	 */
	char getLetter() const override;

	/*!
	 * According to field state, determine the next action for current Vampire
	 *
	 * \param game Field
	 */
	void setAction(Field&) override;
};
