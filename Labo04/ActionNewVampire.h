#pragma once
#include "Action.h"
#include "Field.h"
#include "Vampire.h"


class ActionNewVampire :
	public Action
{
public:
	ActionNewVampire(Humanoid* hum): Action(hum,0,0){}
	void execute(Field& f)
	{
		f.addHumanoid(new Vampire(humanoid->getXPos(), humanoid->getYPos()));
		humanoid->killIt();
	}
};

