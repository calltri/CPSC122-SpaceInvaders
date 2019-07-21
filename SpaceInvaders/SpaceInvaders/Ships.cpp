#include "Ships.h"



Ships::Ships(string textureFile, float width, float length)
{
	spriteTexture.loadFromFile(textureFile);
	this->setTexture(spriteTexture);
	//FIXME get rid of this comment this->setTextureRect(sf::IntRect(0, 0, width, length));
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

