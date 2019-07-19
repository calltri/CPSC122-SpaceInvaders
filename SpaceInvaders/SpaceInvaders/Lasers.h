#pragma once

#include<iostream>
#include<string>
#include"SFML/Graphics.hpp"
#include"Global_Constants.h"

class Lasers : public sf::RectangleShape
{
public:
	/*constructor
	inputs: vector2f of new position
	autos: automatically sets laser to laser Size (see global constants) and blue color*/
	Lasers(sf::Vector2f &newPosition);
	~Lasers();

	/*************************************************************
* Function: moveUpwards()                                      *
* Date Created: 7-19-19                                     *
* Date Last Modified: 7-19-19                             *
* Description:moves the laser upwards. What good guy lasers do
*
* Input parameters: float speed (auto set to LASER_SPEED)                   *
* Returns: none                               *
* Preconditions:  none                                      *
* Postconditions:	none                                    *
*************************************************************/
	void moveUpwards(const float &speed = LASER_SPEED);
	/*************************************************************
* Function: moveDownwards()                                      *
* Date Created: 7-19-19                                     *
* Date Last Modified: 7-19-19                             *
* Description:moves the laser downwards. for enemy lasers
*
* Input parameters: float speed (auto set to LASER_SPEED)                   *
* Returns: none                               *
* Preconditions:  none                                      *
* Postconditions:	none                                    *
*************************************************************/
	void moveDownwards(const float &speed = LASER_SPEED);

private:


};