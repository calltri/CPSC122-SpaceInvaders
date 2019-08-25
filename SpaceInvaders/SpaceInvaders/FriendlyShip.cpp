#include "FriendlyShip.h"

FriendlyShip::FriendlyShip(string textureFile, float width, float length, sf::Vector2f newPosition)
	: Ships(textureFile, width, length)
{
	this->setPosition(newPosition);
	heartTexture.loadFromFile("heartSprite.png");
	healthSprite.setTexture(heartTexture);
	this->points = 0;
	this->mHealth = 3;
}

FriendlyShip::~FriendlyShip()
{

}

void FriendlyShip::movement(float dx)
{
	if (dx < 0 && !(this->getPosition().x < 0))
		move(dx,0);
	if (dx > 0 && !(this->getPosition().x + FRIENDLY_SHIP_WIDTH > WINDOW_WIDTH))
		move(dx, 0);
}

vector<Lasers*> FriendlyShip::laserSpawn() const
{
	vector<Lasers*> allLasers;
	float newX = this->getPosition().x + this->getGlobalBounds().width / 2 - LASER_WIDTH / 2;
	float newY = this->getPosition().y - 2 - LASER_HEIGHT;

	allLasers.push_back(new GoodLaser(*new sf::Vector2f(newX, newY)));

	if (DEBUG == true)
		std::cout << "Laser Spawned\n";

	return allLasers;
}

void FriendlyShip::displayHealth(sf::RenderWindow &window)
{
	healthSprite.setPosition({ 0,2 });
	for (int i = 0; i < mHealth; i++)
	{
		window.draw(healthSprite);
		healthSprite.move(32, 0);
	}
}