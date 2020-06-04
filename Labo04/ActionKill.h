/* -------------------------------------------------------------------
 * File: ActionKill.h
 *
 * Authors: David Dupraz, Soulaymane Lamrani, Alexandre Simik
 *
 * Content: header of ActionKill class
 * 
 * Implemented inline to limit number of files, this class being very small
 *
 * ------------------------------------------------------------------ */
#pragma once
#include "Action.h"

class ActionKill :
	public Action
{
public:
	/*!
	 * Standard constructor for ActionKill
	 * It sets parent values xTo and yTo to 0 because it doesn't need it
	 *
	 * \param hum pointer to humanoid to kill
	 */
	explicit ActionKill(Humanoid* hum) :Action(hum, 0, 0) {}

	/*!
	 * Execute the action: designated humanoid is killed
	 * 
	 * \param f game field
	 */
	void execute(Field& f) override
	{
		humanoid->killIt();
	}
};

