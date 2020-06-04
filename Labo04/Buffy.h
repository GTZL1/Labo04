/* -------------------------------------------------------------------
 * File: Buffy.h
 *
 * Authors: David Dupraz, Soulaymane Lamrani, Alexandre Simik
 *
 * Content: header of Buffy class
 *
 * ------------------------------------------------------------------ */
#pragma once
#include "Humanoid.h"
#include "Vampire.h"
#include "Action.h"
#include "ActionKill.h"
#include "ActionMoveRandom.h"
#include "ActionMoveTo.h"

class Vampire;

class Buffy : public Humanoid
{
	static const size_t HUNTING_RANGE = 1;
	static const char LETTER = 'B';
public:
	/*!
	 * Standard constructor
	 *
	 * \param xPos x start position
	 * \param yPos y start position
	 */
	Buffy(size_t xPos, size_t yPos) :Humanoid(xPos, yPos) {}

	/*!
	 * Get class symbol
	 *
	 * \return class symbol letter
	 */
	char getLetter() const override;

	/*!
	 * According to field state, determine the next action for current Buffy
	 *
	 * \param game Field
	 */
	void setAction(Field&) override;

	/*!
	 * Execute action
	 * Redefined here because Buffy executes it twice
	 * 
	 * \param game field
	 */
	void executeAction(Field&) override;
};

