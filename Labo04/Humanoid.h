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
	
	bool alive = true;
protected:
	//static const char LETTER;
	size_t xPos, yPos;
	Action* action = nullptr;
public:
	Humanoid();
	Humanoid(size_t, size_t);
	virtual bool isAlive();
	virtual size_t getXPos();
	virtual size_t getYPos();
	virtual void setXPos(size_t);
	virtual void setYPos(size_t);
	virtual void setAction(Field&);
	virtual void executeAction(Field&);
	virtual void killIt();
	virtual std::string toString() const;
	virtual char getLetter() const=0;
	virtual ~Humanoid()
	{
		delete action;
	}
};

