#include"AllLasers.h"

AllLasers::AllLasers()
{
}

AllLasers::~AllLasers()
{
	for (int i = 0; i < currentLasers.size(); i++)
	{
		delete currentLasers.at(i);
	}
}

void AllLasers::moveLaser(Lasers &laser)
{
	laser.moveLaser();
}

void AllLasers::moveAllLasers(vector<Lasers*> &allLasers)
{
	for (int i = 0; i < allLasers.size(); i++)
	{
		moveLaser(*allLasers.at(i));
	}
}

void AllLasers::spawnLaser(const Ships & s1)
{
	vector<Lasers*> newLasers = s1.laserSpawn();
	//append newLasers to currentLasers
	currentLasers.insert(currentLasers.end(), newLasers.begin(), newLasers.end());
}

void AllLasers::spawnAllLasers(const vector<Ships*> &allShips)
{
	for (int i = 0; i < allShips.size(); i++)
	{
		spawnLaser(*allShips.at(i));
	}
}

vector<Lasers*> AllLasers::getCurrentLasers() const
{
	return currentLasers;
}
