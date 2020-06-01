// Labo04.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Field.h"
#include "Humanoid.h"


int main()
{
	Field mainField(30,30);
	mainField.populate(5, 10);
	mainField.display();
	for (short x = 0; x < 20; ++x)
	{
		mainField.nextTurn();
		mainField.display();
	}
	
	system("pause");
}
