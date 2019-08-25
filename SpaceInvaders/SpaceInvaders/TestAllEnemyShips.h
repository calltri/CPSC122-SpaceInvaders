#pragma once

#include"AllEnemyShips.h"
#include"BasicEnemy.h"
#include"EnemyBoss.h"
#include"AllLasers.h"
#include"FriendlyShip.h"

class TestAllEnemyShips : protected AllEnemyShips
{
public:
	/****************************************************************
* Function: TestRandomlySpawnNewEnemyShips()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:Tests randomly spawn all ships and draw all ships.
Works if all ships show up on screen
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void TestRandomlySpawnNewEnemyShips();
	/****************************************************************
* Function: TestShipMovement()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:Tests ship movement and out of bounds checks.
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void TestShipMovement();
	/****************************************************************
* Function: TestLaserCollision()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:Tests laser collision and deletes of ship
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void TestLaserCollision();

};