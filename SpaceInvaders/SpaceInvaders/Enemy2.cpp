#include "Enemy2.h"

Enemy2::Enemy2(string textureFile, float width, float length, sf::Vector2f newPosition)
	: Ships(textureFile, width, length)
{
	this->setPosition(generateRandomSpawnPosition(width));
	this->points = 20;
	this->mHealth = 2;
	this->direction = rand() % 3 - 1;
}

Enemy2::~Enemy2()
{

}

void Enemy2::movement()
{
	if (getPosition().x - 3 <= 0)
		direction = 1;
	else if (getPosition().x + 3 >= WINDOW_WIDTH - ENEMY_2_WIDTH)
		direction = -1;
	move({ 4 * (float)direction, 4 });
}

vector<Lasers*> Enemy2::laserSpawn() const
{
	vector<Lasers*> allLasers;
	float newX = this->getPosition().x + this->getGlobalBounds().width / 2 - LASER_WIDTH / 2;
	float newY = this->getPosition().y + this->getGlobalBounds().height + 2;

	allLasers.push_back(new Lasers(*new sf::Vector2f(newX, newY)));

	return allLasers;
}