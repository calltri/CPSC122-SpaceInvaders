#include "EnemyBoss.h"


EnemyBoss::EnemyBoss(string textureFile, float width, float length, sf::Vector2f newPosition)
	: Ships(textureFile, width, length)
{
	this->setPosition(generateRandomSpawnPosition(width));
	this->points = 100;
	this->mHealth = 8;
}

EnemyBoss::~EnemyBoss()
{
}

void EnemyBoss::movement()
{
	if (getPosition().x - 3 <= 0)
		direction = 1;
	else if (getPosition().x + 3 >= WINDOW_WIDTH - ENEMY_SHIP_WIDTH)
		direction = -1;
	move({ 3 * (float)direction, 0 });
}

vector<Lasers*> EnemyBoss::laserSpawn() const
{
	vector<Lasers*> allLasers;

	//spawn center laser
	float newX = this->getPosition().x + this->getGlobalBounds().width / 2 - LASER_WIDTH / 2;
	float newY = this->getPosition().y + this->getGlobalBounds().height + 2;
	allLasers.push_back(new Lasers(*new sf::Vector2f(newX, newY)));

	//spawn right laser
	newX = this->getPosition().x + this->getGlobalBounds().width * 3 / 4 - LASER_WIDTH / 2 + 1;
	allLasers.push_back(new Lasers(*new sf::Vector2f(newX, newY)));

	//spawn left laser
	newX = this->getPosition().x + this->getGlobalBounds().width * 1 / 4 - LASER_WIDTH / 2 - 1;
	allLasers.push_back(new Lasers(*new sf::Vector2f(newX, newY)));

	return allLasers;
}