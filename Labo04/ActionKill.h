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
	ActionKill(Humanoid* hum) :Action(hum, 0, 0) {}

	/*!
	 * Execute the action: designated humanoid is killed
	 * 
	 * \param f game field
	 */
	void execute(Field& f)
	{
		humanoid->killIt();
	}
};

