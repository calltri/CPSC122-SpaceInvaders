#include "Ships.h"



Ships::Ships(string textureFile, float width, float length)
{
	spriteTexture.loadFromFile(textureFile);
	this->setTexture(spriteTexture);
}

Ships::~Ships()
{

}

sf::Vector2f Ships::generateRandomSpawnPosition(float width)
{
	float newX = rand() % (WINDOW_WIDTH - (int)width + 1);
	sf::Vector2f newPosition(newX, 0);

	if (DEBUG == true)
	{
		std::cout << "X is: " << newPosition.x << " Y is: " << newPosition.y << std::endl;
	}
	return newPosition;
}

void Ships::movement()
{
}

void Ships::setHealth(const int & health)
{
	if (health >= 0)
		mHealth = health;
	else
		mHealth = 0;
}

int Ships::getHealth() const
{
	return mHealth;
}

void Ships::decrementHealth(const int & decrement)
{
	mHealth -= decrement;
}

int Ships::getPoints() const
{
	return points;
}

