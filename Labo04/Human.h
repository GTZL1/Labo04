#pragma once
#include "Humanoid.h"
class Human : public Humanoid
{
public:
	static const char LETTER = 'h';
	Human():Humanoid(){}
	Human(size_t xPos, size_t yPos) :Humanoid(xPos, yPos) {}
	char getLetter() const;
	void setAction(Field& f);
};

