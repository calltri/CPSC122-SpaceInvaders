#pragma once
#include"SFML/Graphics.hpp"
#include"Global_Constants.h"
#include <string.h>
#include<vector>
#include"Lasers.h"
#include<cstdlib>

using std::vector;
using std::string;

const bool DEBUG = false;

class Ships : public sf::Sprite
{
public:
	//constructor
	Ships(string textureFile, float width, float length);
	//destructor
	~Ships();
	
	/****************************************************************
* Function: generateRandomSpawnPosition()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description: generates a random starting position (meant for
enemy units only) at the top of the screen such that the enemy
will still be inbounds of everything
* input parameters:float width
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	sf::Vector2f generateRandomSpawnPosition(float width);

	virtual void movement();


	virtual vector<Lasers*> laserSpawn() const = 0;


protected:
	sf::Texture spriteTexture;
	int mHealth;


};