/* -------------------------------------------------------------------
 * File: Humanoid.h
 *
 * Authors: David Dupraz, Soulaymane Lamrani, Alexandre Simik
 *
 * Content: header of Humanoid class
 *
 * ------------------------------------------------------------------ */
#pragma once
#include <string>
#include <random>
#include <iostream>
class Field;
class Action;
class Humanoid;

/*!
 * Operator << overload for Humanoid. Uses the toString() method
 * 
 */
std::ostream& operator<<(std::ostream&, Humanoid&);

class Humanoid
{
	bool alive = true;
	size_t xPos, yPos;
protected:
	Action* action = nullptr;
public:
	/*!
	 * Standard constructor
	 * 
	 * \param x start position
	 * \param y start position
	 */
	Humanoid(size_t, size_t);

	/*!
	 * check if current Humanoid is alive
	 * 
	 * \return if it's alive or not
	 */
	virtual bool isAlive() const;

	/*!
	 * return x position of current Humanoid
	 * 
	 * \return x position
	 */
	virtual size_t getXPos() const;

	/*!
	 * return y position of current Humanoid
	 *
	 * \return y position
	 */
	virtual size_t getYPos() const;

	/*!
	 * set x position of current Humanoid
	 *
	 * \param new x position
	 */
	virtual void setXPos(size_t);

	/*!
	 * set y position of current Humanoid
	 *
	 * \param new y position
	 */
	virtual void setYPos(size_t);

	/*!
	 * For sub-classes: according to field state, determine the next action for current Humanoid
	 * In this abstract class, delete ptr to action to set a new one
	 * 
	 * \param game Field
	 */
	virtual void setAction(Field&);

	/*!
	 * Execute action in field
	 * If action is nullptr, it doesn't execute it (no side effects)
	 * 
	 * \param current field
	 */
	virtual void executeAction(Field&);

	/*!
	 * Kill current Humanoid
	 * Kill a dead Humanoid has no side effect
	 * 
	 */
	virtual void killIt();

	/*!
	 * Return a string to display current Humanoid's symbol
	 * 
	 * \return string with symbol
	 */
	virtual std::string toString() const;

	/*!
	 * Get symbol char of Humanoid subclass (this class is abstract)
	 * 
	 * \return char symbol
	 */
	virtual char getLetter() const=0;

	/*!
	 * Standard destructor
	 * 
	 */
	virtual ~Humanoid();
};

