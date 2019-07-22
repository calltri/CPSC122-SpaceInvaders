#pragma once

#include"Lasers.h"

class GoodLaser : public Lasers
{
public:
	GoodLaser(sf::Vector2f &newPosition);

	/****************************************************************
* Function: moveLaser()										*
* Date Created: 7-19-19											*
* Date Last Modified: 7-19-19									*
* Description:moves the laser upwards. What good guy lasers do  *
* Input parameters: float speed (auto set to LASER_SPEED)		*
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void moveLaser(const float & speed = LASER_SPEED);
};