/* -------------------------------------------------------------------
 * File: Human.cpp
 *
 * Authors: David Dupraz, Soulaymane Lamrani, Alexandre Simik
 *
 * Content: implementation of Human class
 *
 * ------------------------------------------------------------------ */
#include "Human.h"
#include "Action.h"
#include "ActionMoveRandom.h"

char Human::getLetter() const
{
	return Human::LETTER;
}

void Human::setAction(Field& f)
{
	Humanoid::setAction(f);

	action = new ActionMoveRandom(this);
}

