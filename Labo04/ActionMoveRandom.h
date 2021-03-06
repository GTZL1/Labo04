/* -------------------------------------------------------------------
 * File: ActionMoveRandom.h
 *
 * Authors: David Dupraz, Soulaymane Lamrani, Alexandre Simik
 *
 * Content: header of ActionMoveRandom class
 *
 * Implemented inline to limit number of files, this class being very small
 *
 * ------------------------------------------------------------------ */
#pragma once
#include "Action.h"

class ActionMoveRandom :
	public Action
{
public:
	/*!
	 * Standard constructor for ActionMoveRandom
	 * It sets parent values xTo and yTo to 0 because it doesn't need it
	 * 
	 * \param hum pointer to humanoid to move
	 */
	 explicit ActionMoveRandom(Humanoid* hum) :Action(hum, 0, 0){}

	/*!
	 * Execute a random movement of 1 square
	 * 
	 * \param f current game field
	 */
	void execute(Field& f) override
	{
		srand((unsigned)time(0));
		if (rand() % 2)
		{
			humanoid->setXPos((humanoid->getXPos()) + 1);
			humanoid->setYPos((humanoid->getYPos()) + 1);
		}
		else
		{
			humanoid->setXPos((humanoid->getXPos()) - 1);
			humanoid->setYPos((humanoid->getYPos()) - 1);
		}

		//xPos and yPos are size_t, so they are never <0
		//we only check positive overflows
		if (humanoid->getXPos() >= f.getXSize())
		{
			humanoid->setXPos(f.getXSize() - 1);
		}
		if (humanoid->getYPos() >= f.getYSize())
		{
			humanoid->setYPos(f.getYSize() - 1);
		}
	}
};

