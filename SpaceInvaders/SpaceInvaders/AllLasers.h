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
* input parameters:vector<Lasers*> &allLasers
* Returns: none													*
* Preconditions:  none											*
* Postconditions:	none										*
*****************************************************************/
	void moveAllLasers(vector<Lasers*> &allLasers);

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

	//getter
	vector<Lasers*> getCurrentLasers() const;

protected:
	vector<Lasers*> currentLasers;

};