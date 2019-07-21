#include"GoodLaser.h"

GoodLaser::GoodLaser(sf::Vector2f & newPosition) : Lasers(newPosition)
{
}

void GoodLaser::moveLaser(const float & speed)
{
	Lasers::moveLaser(-speed);
}
