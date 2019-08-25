/*******************************************************************************
 * Programmer: Tristan Call, Dominic Davok, Chandler Teigen                    *
 * Class: CptS 122; Lab Section 1                                              *
 * Programming Assignment: PA8                                                 *
 * Date: 7-19-19                                                               *
 *                                                                             *
 * Description: variant of space invaders												   *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record in input file:none										   *	
 *																			   *
 * Format of output file:none												   *

 notes:
 ******************************************************************************/


#include"SFML/Graphics.hpp"
#include"Lasers.h"
#include"GoodLaser.h"
#include"Global_Constants.h"
#include "Ships.h"
#include "BasicEnemy.h"
#include "HealthDisplay.h"
#include "Game.h"
#include <vector>
#include"TestAllLasers.h"
#include<ctime>
#include<cstdlib>
#include"TestAllEnemyShips.h"

using std::vector;

int main()
{
	TestAllLasers test1;
	TestAllEnemyShips test2;
	srand(time(0));

	Game g1;
	g1.run();

	//test2.TestRandomlySpawnNewEnemyShips();
	//test2.TestShipMovement();
	//test2.TestLaserCollision();

	//test1.TestIfSpawningGeneratesCollision();
	//test1.TestCheckIfCollision();
	//test1.TestDeleteLasersOutOfBound();
	//test1.TestSpawnAllLasers();
	//test1.TestMoveAllLasers();
}
