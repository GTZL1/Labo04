#pragma once
#include "Humanoid.h"
class Human : public Humanoid
{
public:
	static const char LETTER = 'h';
	
	/*!
	 * Standard constructor
	 * 
	 * \param xPos x start position
	 * \param yPos y start position
	 */
	Human(size_t xPos, size_t yPos) :Humanoid(xPos, yPos) {}

	/*!
	 * Get class symbol
	 * 
	 * \return class symbol letter
	 */
	char getLetter() const;

	/*!
	 * According to field state, determine the next action for current Human
	 *
	 * \param game Field
	 */
	void setAction(Field&);
};

