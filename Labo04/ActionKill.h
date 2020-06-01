#pragma once
#include "Action.h"
class ActionKill :
	public Action
{
public:
	ActionKill(Humanoid* hum) :Action(hum, 0, 0) {}
	void execute(Field& f)
	{
		humanoid->killIt();
	}
};

