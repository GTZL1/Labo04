#pragma once
#include <iostream>
#include <string>

#include "Field.h"
#include "Humanoid.h"
#include "Vampire.h"
#include "Human.h"

class GameMaster
{
	const std::string QUIT_COMMAND = "uit";
	const std::string NEXT_COMMAND = "ext";
	const std::string STATS_COMMAND = "tats";
	static const char PROMPT_CHAR = '>';
	static const char QUIT_CHAR = 'q';
	static const char NXT_CHAR = 'n';
	static const char STATS_CHAR = 's';
	const double NB_TESTS = 10000;


	void displayPrompt(size_t turn)
	{
		std::cout << "[" << turn << "] " << QUIT_CHAR << PROMPT_CHAR << QUIT_COMMAND << " "
			<< STATS_CHAR << PROMPT_CHAR << STATS_COMMAND << " " << NXT_CHAR << PROMPT_CHAR << NEXT_COMMAND << std::endl;
	}

	size_t runMultipleGames(size_t nbVampires, size_t nbHumans, size_t xFieldSize, size_t yFieldSize)
	{
		Field field(50, 50);
		double buffyVictories = 0;
		for (double x = 0; x < NB_TESTS; ++x)
		{
			field.clearContent();
			field.populate(10, 20);
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

public:
	void runGame(Field& mainField, size_t nbVampires, size_t nbHumans)
	{
		mainField.populate(nbVampires,nbHumans);

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
						runMultipleGames(nbVampires, nbHumans,mainField.getXSize(), mainField.getYSize()) << "%" << std::endl;
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
};
