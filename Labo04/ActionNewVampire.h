/* -------------------------------------------------------------------
 * File: ActionNewVampire.h
 *
 * Authors: David Dupraz, Soulaymane Lamrani, Alexandre Simik
 *
 * Content: header of ActionNewVampire class
 *
 * Implemented inline to limit number of files, this class being very small
 *
 * ------------------------------------------------------------------ */
#pragma once
#include "Action.h"
#include "Field.h"
#include "Vampire.h"

class ActionNewVampire :
	public Action
{
public:
	/*!
	 * Standard constructor for ActionNewVampire
	 * It sets parent values xTo and yTo to 0 because it doesn't need it
	 *
	 * \param hum pointer to humanoid to transform into vampire
	 */
	ActionNewVampire(Humanoid* hum): Action(hum,0,0){}

	/*!
	 * Execute the action: designated humanoid is killed and a new vampire takes his place
	 * 
	 * \param f game field
	 */
	void execute(Field& f)
	{
		f.addHumanoid(new Vampire(humanoid->getXPos(), humanoid->getYPos()));
		humanoid->killIt();
	}
};

