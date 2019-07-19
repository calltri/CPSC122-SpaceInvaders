#include"Lasers.h"

Lasers::Lasers(sf::Vector2f &newPosition) : sf::RectangleShape(*new sf::Vector2f(LASER_WIDTH, LASER_HEIGHT))
{
	setFillColor(sf::Color::Blue);
	setPosition(newPosition);

}

Lasers::~Lasers()
{
}

void Lasers::moveUpwards(const float & speed)
{
	move(0.0, -speed);
}

void Lasers::moveDownwards(const float & speed)
{
	move(0.0, speed);
}
