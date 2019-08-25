#pragma once
#include "Ships.h"
#include"BasicEnemy.h"
#include"Enemy2.h"
#include"EnemyBoss.h"
#include<vector>

using std::vector;

class AllEnemyShips
{
public:
	AllEnemyShips();
	~AllEnemyShips();

	/****************************************************************
* Function: moveShip()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:moves single ship in given vector according to their
specific movement function
* input parameters:Ships &ship
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void moveShip(Ships &ship);
	/****************************************************************
* Function: moveAllEnemyShips()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:moves all lasers in given vector according to their
specific movement function
* input parameters:none
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void moveAllEnemyShips();

	/****************************************************************
* Function: randomlySpawnNewEnemyShips()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description: randomly spawns new enemies and adds to currentEnemies.
The frequency of spawning can be increased by having a higher frequency value
* input parameters:const double &fequency = 1.0
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void randomlySpawnNewEnemyShips(const double &fequency = 1.0);

	/****************************************************************
* Function: checkOutOfBounds()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:checks if lasers is out of bounds. If yes, returns true
* Input Parameters: Ships &ship
* Returns: bool													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	bool checkOutOfBounds(Ships &ship);
	/****************************************************************
* Function: deleteShipsOutOfBound()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:deletes all out of bound lasers
* Input Parameters: none
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void deleteShipsOutOfBound();
	/****************************************************************
* Function: deleteShip()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:deletes a single laser in the vector currentLasers
at index i
* Input Parameters: int i
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void deleteShip(int i);

	/****************************************************************
* Function: checkIfCollision()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:checks if there is a collision between two ships.
returns true if there is, false otherwise
* Input Parameters: const Ships &s1, const Ships &s2
* Returns: bool													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	bool checkIfCollision(const Ships &s1, const Ships &s2);
	/****************************************************************
* Function: checkIfShipCollisionWithAnyShip()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:checks if there is a collision between a ship and
any existing EnemyShip. If yes, decrements  both ship's health
* Input Parameters: ships &s1
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void checkIfShipCollisionWithAnyShip(Ships &s1);

	/****************************************************************
* Function: checkIfShipDestroyed(()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:checks if ship is out of health. If yes, returns true
* Input Parameters: Ships &s1
* Returns: bool													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	bool checkIfShipDestroyed(Ships &s1);
	/****************************************************************
* Function: checkIfEnemyShipsDestroyed(()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:checks all Enemy ships if they are out of health. 
returns total number of points from destroyed ships
* Input Parameters: none
* Returns: int													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	int checkIfEnemyShipsDestroyed();

	/****************************************************************
* Function: drawAllEnemyShips()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:draws all enemyShips to gameWindow
* Input Parameters: sf::RenderWindow &gameWindow
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void drawAllEnemyShips(sf::RenderWindow &gameWindow);

	//getter
	vector<Ships*> getCurrentEnemyShips() const;
	vector<Ships*>& getAndModifyCurrentEnemyShips();

protected:
	vector<Ships*> currentShips;
};

