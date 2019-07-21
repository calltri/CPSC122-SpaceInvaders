#include "BasicEnemy.h"

BasicEnemy::BasicEnemy(string textureFile, float width, float length, sf::Vector2f newPosition) 
	: Ships(textureFile, width, length)
{
	this->setPosition(generateRandomSpawnPosition(width));
	
}

BasicEnemy::~BasicEnemy()
{

}

vector<Lasers*> BasicEnemy::laserSpawn() const
{
	vector<Lasers*> allLasers;
	float newX = this->getPosition().x + this->getGlobalBounds().width / 2 - LASER_WIDTH / 2;
	float newY = this->getPosition().y + this->getGlobalBounds().height + 2;

	allLasers.push_back(new Lasers(*new sf::Vector2f(newX, newY)));

	return allLasers;
}
