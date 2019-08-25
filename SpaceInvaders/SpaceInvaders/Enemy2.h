#pragma once
#include "Ships.h"
class Enemy2 : public Ships
{
public:
	//constructor
	Enemy2(string textureFile = "enemySprite2.png", float width = ENEMY_2_WIDTH,
		float length = ENEMY_2_HEIGHT, sf::Vector2f newPosition = *(new sf::Vector2f(0, 0)));
	//destructor
	~Enemy2();
	//public member functions
	/****************************************************************
	* Function: movement()										    *
	* Date Created: 7-22-19											*
	* Date Last Modified: 7-22-19									*
	* Description: movement function for the basic enemy, checks
	*			   boundaries to prevent moving out of screen
	* Input parameters: None								        *
	* Returns: void													*
	* Preconditions: none											*
	* Postconditions:	none										*
	*****************************************************************/
	void movement();
	vector<Lasers*> laserSpawn() const;

private:
	int direction;

};