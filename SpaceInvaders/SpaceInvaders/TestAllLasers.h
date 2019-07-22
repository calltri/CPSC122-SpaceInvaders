#pragma once

#include"AllLasers.h"
#include"BasicEnemy.h"

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
	void TestSpawnAllLasers();


};