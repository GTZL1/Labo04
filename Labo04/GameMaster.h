/* -------------------------------------------------------------------
 * File: GameMaster.h
 *
 * Authors: David Dupraz, Soulaymane Lamrani, Alexandre Simik
 *
 * Content: header of GameMaster class
 *
 * ------------------------------------------------------------------ */
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
	const double NB_TESTS;

	/*!
	 * Display the prompt with current turn number and possible commands
	 * 
	 * \param current turn number
	 */
	void displayPrompt(size_t);

	/*!
	 * Run without display it NB_TESTS iterations of the game
	 * 
	 * \param nb of vampires
	 * \param nb of humans
	 * \param x size of field
	 * \param y size of field
	 * \return Buffy's success rate
	 */
	size_t runMultipleGames(size_t, size_t, size_t, size_t);

public:
	/*!
	 * Standard constructor
	 * 
	 * \param number of tests to do. Type is double for calcul precision
	 */
	GameMaster(double);

	/*!
	 * Run an iteration of the game and display each turn
	 * 
	 * \param game field
	 * \param number of vampires
	 * \param number of humans
	 */
	void runGame(Field&, size_t, size_t);
};
