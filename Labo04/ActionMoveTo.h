/* -------------------------------------------------------------------
 * File: ActionMoveTo.h
 *
 * Authors: David Dupraz, Soulaymane Lamrani, Alexandre Simik
 *
 * Content: header of ActionMoveTo class
 *
 * Implemented inline to limit number of files, this class being very small
 *
 * ------------------------------------------------------------------ */
#pragma once
#include "Action.h"

class ActionMoveTo :
	public Action
{
public:
	/*!
	 * Standard constructor for ActionMoveTo
	 *
	 * \param hum pointer to humanoid to move
	 * \param x coordinate to go to
	 * \param y coordinate to go to
	 */
	ActionMoveTo(Humanoid* hum, size_t xTo, size_t yTo) :Action(hum, xTo, yTo){}

	/*!
	 * Execute movement of 1 square to the (xTo, yTo) point
	 * 
	 * \param f game field
	 */
	void execute(Field& f) override
	{
		if (xTo < humanoid->getXPos())
		{
			humanoid->setXPos(humanoid->getXPos() - 1);
			if (yTo < humanoid->getYPos())
			{
				humanoid->setYPos(humanoid->getYPos() - 1);
			}
			else if (yTo > humanoid->getYPos())
			{
				humanoid->setYPos(humanoid->getYPos() + 1);
			}
		}
		else if (xTo > humanoid->getXPos())
		{
			humanoid->setXPos(humanoid->getXPos() + 1);
			if (yTo < humanoid->getYPos())
			{
				humanoid->setYPos(humanoid->getYPos() - 1);
			}
			else if (yTo > humanoid->getYPos())
			{
				humanoid->setYPos(humanoid->getYPos() + 1);
			}
		}
		else
		{
			if (yTo < humanoid->getYPos())
			{
				humanoid->setYPos(humanoid->getYPos() - 1);
			}
			else if (yTo > humanoid->getYPos())
			{
				humanoid->setYPos(humanoid->getYPos() + 1);
			}
		}
	}
};

