#pragma once
#include "Ships.h"
class EnemyBoss : public Ships
{
public:
	//constructor
	EnemyBoss(string textureFile = "enemyShipSprite.png", float width = ENEMY_SHIP_WIDTH,
		float length = ENEMY_SHIP_HEIGHT, sf::Vector2f newPosition = *(new sf::Vector2f(0, 0)));
	//destructor
	~EnemyBoss();
	//public member functions
	/****************************************************************
	* Function: movement()										    *
	* Date Created: 7-22-19											*
	* Date Last Modified: 7-22-19									*
	* Description: the movement function for the enemy ship, checks
	*			   boundaries to prevent moving out of screen
	* Input parameters: None								        *
	* Returns: void													*
	* Preconditions: none											*
	* Postconditions:	none										*
	*****************************************************************/
	void movement();
	vector<Lasers*> laserSpawn() const;
	
private:
	int direction = 1;

};

