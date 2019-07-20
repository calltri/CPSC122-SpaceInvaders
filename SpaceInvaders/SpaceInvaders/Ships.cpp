#include "Ships.h"



Ships::Ships(string textureFile, float width, float length)
{
	spriteTexture.loadFromFile(textureFile);
	this->setTexture(spriteTexture);
	this->setTextureRect(sf::IntRect(0, 0, width, length));
}

Ships::~Ships()
{

}

void Ships::movement()
{
}

void Ships::laserSpawn()
{
}
