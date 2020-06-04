/* -------------------------------------------------------------------
 * File: Action.h
 *
 * Authors: David Dupraz, Soulaymane Lamrani, Alexandre Simik
 *
 * Content: header of Action class
 *
 * Implemented inline to limit number of files, this class being very small
 *
 * ------------------------------------------------------------------ */
#pragma once
#include <ctime>

#include "Humanoid.h"
#include "Field.h"

class Action
{
protected:
	Humanoid* humanoid;
	size_t xTo, yTo; //point to go to not used by sub-classes ActionMoveRandom, ActionKill, ActionNewVampire
public:
	/*!
	 * Standard constructor
	 * 
	 * \param hum pointer to humanoid concerned by action
	 * \param x coordinate to go to
	 * \param y coordinate to go to
	 */
	Action(Humanoid* hum, size_t x, size_t y) :humanoid(hum), xTo(x), yTo(y) {}

	/*!
	 * Execute action
	 * 
	 * \param game field
	 */
	virtual void execute(Field&) = 0;

	/*!
	 * Standard destructor
	 * 
	 */
	virtual ~Action(){}
};

