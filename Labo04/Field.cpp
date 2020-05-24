#include "Field.h"
#include "Humanoid.h"
#include "Vampire.h"
#include "Human.h"
#include "Buffy.h"

using namespace std;

std::string Field::firstAndBottomLine()
{
	std::string result = "";
	result += edgeChar;
	for (unsigned x = 0; x < xSize; ++x)
	{
		result += delimiterHorizontal;
	}
	return (result += edgeChar);
}

Field::Field(size_t xSize, size_t ySize):xSize(xSize), ySize(ySize)
{}

void Field::populate(size_t nbVampires, size_t nbHumans)
{
	srand((unsigned)time(0));

	for (size_t x = 0; x < nbHumans; ++x)
	{
		humanoids.emplace_back(new Human(rand()% xSize, rand()%ySize));
	}
	for (size_t x = 0; x < nbVampires; ++x)
	{
		humanoids.emplace_back(new Vampire(rand() % xSize, rand() % ySize));
	}
	humanoids.emplace_back(new Buffy(rand() % xSize, rand() % ySize));
}

void Field::display()
{
	for (unsigned y = 0; y < ySize+2; ++y)
	{
		if (!y || y == (xSize + 1))
		{
			cout << firstAndBottomLine() << endl;
			continue;
		}
		else
		{
			cout << delimiterVertical;
			for (unsigned x = 0; x < xSize; ++x)
			{			
				bool humanoidHere = false;
				for (Humanoid* h : humanoids)
				{
					if (h->getXPos() == x && h->getYPos() == y)
					{
						cout << (*h);
						humanoidHere = true;
					}
				}

				if (!humanoidHere)
				{
					cout << ' ';
				}	
			}
			cout << delimiterVertical << endl;
		}
	}
}

int Field::nextTurn()
{
	// Déterminer les prochaines actions
	for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
	{
		(*it)->setAction(*this);
	}
		
	// Executer les actions
	for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
	{
		//(*it)->executeAction(*this);
	}	

	// Enlever les humanoides tués
	for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); )
	{
		if (!(*it)->isAlive())
		{
			it = humanoids.erase(it); // suppression de l’élément dans la liste
			delete *it; // destruction de l’humanoide référencé
		}
		else
		{
			++it;
		}		
	}	

	return turn++;
}

template<typename U>
U* Field::findNearest(size_t x, size_t y)
{
	unsigned short minDistance = -1;
	U* nearest = nullptr;
	for (U* h : humanoids)
	{
		unsigned short newDistance= getDistance(x, h->getXPos(), y, h->getYPos());
		if (newDistance < minDistance)
		{
			minDistance = newDistance;
			nearest = h;
		}
	}
	return nullptr;
}

size_t Field::getDistance(size_t x0, size_t x1, size_t y0, size_t y1)
{
	return (x1 - x0) + (y1 - y0);
}

Field::~Field()
{
	for (Humanoid* h : humanoids)
	{
		delete h;
	}
}
