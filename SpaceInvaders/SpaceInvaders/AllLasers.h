#pragma once

#include"Lasers.h"
#include"GoodLaser.h"
#include<vector>
#include"Ships.h"

using std::vector;

//contains all lasers for main and functions for using them
class AllLasers
{
public:
	AllLasers();
	~AllLasers();

	/****************************************************************
* Function: moveLaser()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:moves single laser in given vector according to their
specific movement function
* input parameters:Lasers &laser
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void moveLaser(Lasers &laser);
	/****************************************************************
* Function: moveAllLasers()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:moves all lasers in given vector according to their
specific movement function
* input parameters:none
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void moveAllLasers();

	/****************************************************************
* Function: spawnLaser()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:spawns lasers for single ship and adds them 
to currentLasers
* Input Parameters: const Ships &s1
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void spawnLaser(const Ships &s1);
	/****************************************************************
* Function: spawnAllLasers()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:spawns lasers for all ships and adds them
to currentLasers
* Input Parameters: const vector<Ships*> &allShips
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void spawnAllLasers(const vector<Ships*> &allShips);

	/****************************************************************
* Function: checkOutOfBounds()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:checks if laser is out of bounds. If yes, returns true
* Input Parameters: Lasers &laser
* Returns: bool													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	bool checkOutOfBounds(Lasers &laser);
	/****************************************************************
* Function: deleteLasersOutOfBound()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:deletes all out of bound lasers
* Input Parameters: none
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void deleteLasersOutOfBound();
	/****************************************************************
* Function: deleteLaser()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:deletes a single laser in the vector currentLasers
at index i
* Input Parameters: int i
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void deleteLaser(int i);

	/****************************************************************
* Function: checkIfCollision()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:checks if there is a collision between a ship and laser.
returns true if there is, false otherwise
* Input Parameters: const Ships &s1, const Lasers &l1
* Returns: bool													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	bool checkIfCollision(const Ships &s1, const Lasers &l1);
	/****************************************************************
* Function: checkIfShipCollisionWithAnyLaser()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:checks if there is a collision between a ship and 
any existing laser. If yes, deletes that laser and decrements ship
health
* Input Parameters: ships &s1
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void checkIfShipCollisionWithAnyLaser(Ships &s1);
	/****************************************************************
* Function: checkIfEnemyLaserCollision()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:checks if there is a collision between any ship in allShips
and any existing laser. If yes, deletes that laser and decrements ship
health
* Input Parameters: vector<Ships*> &allShips
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void checkIfEnemyLaserCollision(vector<Ships*> &allShips);

	/****************************************************************
* Function: drawAllLasers()                                     *
* Date Created: 7-21-19											*
* Date Last Modified: 7-21-19									*
* Description:draws all lasers to gameWindow
* Input Parameters: sf::RenderWindow &gameWindow
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void drawAllLasers(sf::RenderWindow &gameWindow);

	//getter
	vector<Lasers*> getCurrentLasers() const;

protected:
	vector<Lasers*> currentLasers;

};