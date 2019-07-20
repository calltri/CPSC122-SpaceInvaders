#pragma once
#include "Lasers.h"
#include "Ships.h"

class BasicEnemy : public Ships
{
public:
	//constructor
	BasicEnemy(string textureFile = "enemyBasicSprite.png", float width = ENEMY_BASIC_HEIGHT, 
		float length = ENEMY_BASIC_HEIGHT, sf::Vector2f newPosition = *(new sf::Vector2f(0,0)));
	//destructor
	~BasicEnemy();




private:


};