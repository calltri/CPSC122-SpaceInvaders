#pragma once

#include "Ships.h"
#include "Global_Constants.h"
#include "GoodLaser.h"
#include "HealthDisplay.h"
using std::string;

class FriendlyShip : public Ships
{
public:
	//constructor
	FriendlyShip(string textureFile = "friendlyShipSprite.png", float width = FRIENDLY_SHIP_WIDTH,
		float length = FRIENDLY_SHIP_HEIGHT, sf::Vector2f newPosition = 
		*(new sf::Vector2f(WINDOW_WIDTH / 2 - FRIENDLY_SHIP_WIDTH / 2, WINDOW_HEIGHT - FRIENDLY_SHIP_HEIGHT - 10)));
	//destructor
	~FriendlyShip();
	//public member functions
		/****************************************************************
	* Function: movement()										    *
	* Date Created: 7-22-19											*
	* Date Last Modified: 7-22-19									*
	* Description: the movement function for the player ship, checks
	*			   boundaries to prevent moving out of screen
	* Input parameters: direction							        *
	* Returns: void													*
	* Preconditions: none											*
	* Postconditions:	none										*
	*****************************************************************/
	void movement(float dx);
	vector<Lasers*> laserSpawn() const;
	/****************************************************************
* Function: displayHealth()									    *
* Date Created: 7-22-19											*
* Date Last Modified: 7-22-19									*
* Description: Displays the health of the player
* Input parameters: game window							        *
* Returns: void													*
* Preconditions: none											*
* Postconditions:	none										*
*****************************************************************/
	void displayHealth(sf::RenderWindow &window);

private:
	sf::Texture heartTexture;
	sf::Sprite healthSprite;
};