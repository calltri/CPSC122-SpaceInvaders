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

	/****************************************************************
* Function: spawnLaser()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:spawns lasers for single ship in right position
* Input Parameters: none
* Returns: vector<Lasers*> - vector to all lasers the ship spawned													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	vector<Lasers*> laserSpawn() const;


private:


};

