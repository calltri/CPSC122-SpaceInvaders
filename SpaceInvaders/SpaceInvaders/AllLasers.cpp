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

void AllLasers::moveAllLasers()
{
	for (int i = 0; i < currentLasers.size(); i++)
	{
		moveLaser(*currentLasers.at(i));
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

bool AllLasers::checkOutOfBounds(Lasers & laser)
{
	if (laser.getPosition().y > WINDOW_HEIGHT || laser.getPosition().y < 0) //if out of top/bottom bounds
	{
		return true;
	}
	else if (laser.getPosition().x > WINDOW_WIDTH || laser.getPosition().x < 0)
		return true;
	return false;
}

void AllLasers::deleteLasersOutOfBound()
{
	for (int i = 0; i < currentLasers.size(); i++)
	{
		if (checkOutOfBounds(*currentLasers.at(i)))
		{
			deleteLaser(i);
		}
	}
}

void AllLasers::deleteLaser(int i)
{
	delete currentLasers.at(i); //deletes laser
	currentLasers.erase(currentLasers.begin() + i); //deletes ptr to deleted laser
}

bool AllLasers::checkIfCollision(const Ships & s1, const Lasers & l1)
{
	bool collision = false;

	float shipTop = s1.getPosition().y;
	float shipBot = s1.getPosition().y + s1.getGlobalBounds().height;
	float shipLeft = s1.getPosition().x;
	float shipRight = s1.getPosition().x + s1.getGlobalBounds().width;

	float laserTop = l1.getPosition().y;
	float laserBot = l1.getPosition().y + l1.getGlobalBounds().height;
	float laserLeft = l1.getPosition().x;
	float laserRight = l1.getPosition().x + l1.getGlobalBounds().width;

	if (shipTop > laserBot ||
		shipBot < laserTop ||
		shipLeft > laserRight ||
		shipRight < laserLeft)
	{
		collision = false;
	}
	else 
		collision = true;

	return collision;
}

void AllLasers::checkIfShipCollisionWithAnyLaser(Ships & s1)
{
	for (int i = 0; i < currentLasers.size(); i++)
	{
		if (checkIfCollision(s1, *currentLasers.at(i))) //if collision delete laser and decrement health
		{
			if (DEBUG == true)
				std::cout << "Collision!\n";
			s1.decrementHealth();
			deleteLaser(i);
		}
	}
}

void AllLasers::checkIfEnemyLaserCollision(vector<Ships*>& allShips)
{
	for (int i = 0; i < allShips.size(); i++)
	{
		checkIfShipCollisionWithAnyLaser(*allShips.at(i));
	}
}

void AllLasers::drawAllLasers(sf::RenderWindow &gameWindow)
{
	for (int i = 0; i < currentLasers.size(); i++)
	{
		gameWindow.draw(*currentLasers.at(i));
	}
}

vector<Lasers*> AllLasers::getCurrentLasers() const
{
	return currentLasers;
}
