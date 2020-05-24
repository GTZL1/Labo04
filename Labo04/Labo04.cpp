// Labo04.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Field.h"
#include "Humanoid.h"


int main()
{
	Field mainField(50,50);
	mainField.populate(10, 20);
	mainField.display();

	system("pause");
}
