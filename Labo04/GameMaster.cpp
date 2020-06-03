/* -------------------------------------------------------------------
 * File: GameMaster.cpp
 *
 * Authors: David Dupraz, Soulaymane Lamrani, Alexandre Simik
 *
 * Content: implementation of GameMaster class
 *
 * ------------------------------------------------------------------ */
#pragma once
#include "GameMaster.h"

void GameMaster::displayPrompt(size_t turn)
{
	std::cout << "[" << turn << "] " << QUIT_CHAR << PROMPT_CHAR << QUIT_COMMAND << " "
		<< STATS_CHAR << PROMPT_CHAR << STATS_COMMAND << " " << NXT_CHAR << PROMPT_CHAR << NEXT_COMMAND << std::endl;
}

size_t GameMaster::runMultipleGames(size_t nbVampires, size_t nbHumans, size_t xFieldSize, size_t yFieldSize)
{
	Field field(xFieldSize, yFieldSize);
	double buffyVictories = 0;
	for (double x = 0; x < NB_TESTS; ++x)
	{
		field.clearContent();
		field.populate(nbVampires, nbHumans);
		//while there are vampires
		while (field.findNearest<Vampire>(0, 0) != nullptr)
		{
			field.nextTurn();
		}

		//look for at least one human
		if (field.findNearest<Human>(0, 0) != nullptr)
		{
			++buffyVictories;
		}
	}

	return ((buffyVictories / NB_TESTS)*100.0);
}

GameMaster::GameMaster(double nbTests): NB_TESTS(nbTests)
{}

void GameMaster::runGame(Field& mainField, size_t nbVampires, size_t nbHumans)
{
	mainField.populate(nbVampires, nbHumans);

	while (1)
	{
		mainField.display();

		size_t turn = mainField.nextTurn();
		char command;
		bool cmdInput = false;
		while (!cmdInput)
		{
			displayPrompt(turn);

			std::cin >> command;
			switch (command)
			{
			case QUIT_CHAR:
				exit(EXIT_SUCCESS);
				break;
			case STATS_CHAR:
				std::cout << "Success rate : " <<
					runMultipleGames(nbVampires, nbHumans, mainField.getXSize(), mainField.getYSize()) << "%" << std::endl;
				break;
			case NXT_CHAR:
				cmdInput = true;
				break;
			default:
				std::cout << "Command unknown" << std::endl;
				break;
			}
		}
	}
}
