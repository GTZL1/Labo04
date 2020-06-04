// Labo04.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>

#include "GameMaster.h"

using namespace std;

int main()
{
	Field mainField(50, 50);
	GameMaster gameMaster(10000);
	gameMaster.runGame(mainField, 10, 20);
}
