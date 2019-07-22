#include "BasicEnemy.h"

BasicEnemy::BasicEnemy(string textureFile, float width, float length, sf::Vector2f newPosition) 
	: Ships(textureFile, width, length)
{
	this->setPosition(newPosition);
	
}

BasicEnemy::~BasicEnemy()
{

}