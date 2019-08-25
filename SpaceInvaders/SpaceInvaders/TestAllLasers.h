#pragma once

#include"AllLasers.h"
#include"BasicEnemy.h"
#include"EnemyBoss.h"
#include"AllEnemyShips.h"

class TestAllLasers : protected AllLasers
{
public:
	/****************************************************************
* Function: testMoveAllLasers()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:Tests moveAllLasers. The two on the left (Lasers) should
move down, the two on the right(GoodLaser) should move up
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void TestMoveAllLasers();
	/****************************************************************
* Function: testSpawnAllLasers()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:Tests spawnAllLasers. 1 laser should appear below each
appearing ships
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void TestSpawnAllLasers();
	/****************************************************************
* Function: testDeleteLasersOutOfBound()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:Tests if laser vector is empty when lasers leave window
bounds
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void TestDeleteLasersOutOfBound();
	/****************************************************************
* Function: testCheckIfCollision()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:Tests if laser has impacted ship
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void TestCheckIfCollision();
	/****************************************************************
* Function: TestIfSpawningGeneratesCollision()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:Tests if laser has impacted ship at spawning
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void TestIfSpawningGeneratesCollision();




};