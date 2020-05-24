#include "Vampire.h"
#include "Human.h"

void Vampire::setAction(Field& f)
{
	Humanoid::setAction(f);
	
	Human* nearest = f.findNearest<Human>(this->xPos, this->yPos);

	//si la distance est moins que 1, on attaque, sinon on bouge
}
