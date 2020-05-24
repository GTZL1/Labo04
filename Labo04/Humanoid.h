#pragma once
#include <string>
#include <random>
#include <iostream>
class Field;
class Action;
class Humanoid;

std::ostream& operator<<(std::ostream&, Humanoid&);

class Humanoid
{
	const char letter;
	bool alive = true;
protected:
	size_t xPos, yPos;
	Action* action = nullptr;
public:
	Humanoid(char letter);
	Humanoid(size_t, size_t, char letter);
	virtual bool isAlive();
	virtual size_t getXPos();
	virtual size_t getYPos();
	virtual void setAction(Field&);
	//virtual void executeAction(Field&);
	virtual std::string toString() const;
};

