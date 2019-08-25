#include "AllEnemyShips.h"



AllEnemyShips::AllEnemyShips()
{

}


AllEnemyShips::~AllEnemyShips()
{
	for (int i = 0; i < currentShips.size(); i++)
	{
		deleteShip(i);
	}
}

void AllEnemyShips::moveShip(Ships &ship)
{
	ship.movement();
}

void AllEnemyShips::moveAllEnemyShips()
{
	for (int i = 0; i < currentShips.size(); i++)
	{
		moveShip(*currentShips.at(i));
	}
}

void AllEnemyShips::randomlySpawnNewEnemyShips(const double &frequency)
{
	int randomNum = rand() % 10000 + 1;

	if(randomNum < frequency * 10)
		currentShips.push_back(new EnemyBoss);
	else if(randomNum < frequency * 30)
		currentShips.push_back(new Enemy2);
	else if (randomNum < frequency * 60)
		currentShips.push_back(new BasicEnemy);
}

bool AllEnemyShips::checkOutOfBounds(Ships & ship)
{
	if (ship.getPosition().y > WINDOW_HEIGHT || ship.getPosition().y < 0) //if out of top/bottom bounds
	{
		return true;
	}
	else if (ship.getPosition().x > WINDOW_WIDTH || ship.getPosition().x < 0)
		return true;
	return false;
}

void AllEnemyShips::deleteShipsOutOfBound()
{
	for (int i = 0; i < currentShips.size(); i++)
	{
		if (checkOutOfBounds(*currentShips.at(i)))
		{
			deleteShip(i);
		}
	}
}

void AllEnemyShips::deleteShip(int i)
{
	delete currentShips.at(i); //deletes ship
	currentShips.erase(currentShips.begin() + i); //deletes ptr to deleted ship
	if (DEBUG == true)
		std::cout << "Ship Deleted\n";
}

bool AllEnemyShips::checkIfCollision(const Ships & s1, const Ships & s2)
{
	bool collision = false;

	float shipTop = s1.getPosition().y;
	float shipBot = s1.getPosition().y + s1.getGlobalBounds().height;
	float shipLeft = s1.getPosition().x;
	float shipRight = s1.getPosition().x + s1.getGlobalBounds().width;

	float ship2Top = s2.getPosition().y;
	float ship2Bot = s2.getPosition().y + s1.getGlobalBounds().height;
	float ship2Left = s2.getPosition().x;
	float ship2Right = s2.getPosition().x + s1.getGlobalBounds().width;

	if (shipTop > ship2Bot ||
		shipBot < ship2Top ||
		shipLeft > ship2Right ||
		shipRight < ship2Left)
	{
		collision = false;
	}
	else
		collision = true;

	return collision;
}

void AllEnemyShips::checkIfShipCollisionWithAnyShip(Ships & s1)
{
	for (int i = 0; i < currentShips.size(); i++)
	{
		if (checkIfCollision(s1, *currentShips.at(i))) //if collision delete laser and decrement health
		{
			s1.decrementHealth();
			currentShips.at(i)->decrementHealth();
		}
	}
}

bool AllEnemyShips::checkIfShipDestroyed(Ships & s1)
{
	if (s1.getHealth() <= 0)
	{
		return true;
	}
	return false;
}

int AllEnemyShips::checkIfEnemyShipsDestroyed()
{
	int points = 0;

	for (int i = 0; i < currentShips.size(); i++)
	{
		if(DEBUG == true)
			std::cout << currentShips.at(i)->getHealth() << std::endl;
		if (currentShips.at(i)->getHealth() <= 0)
		{
			
			points += currentShips.at(i)->getPoints();
			deleteShip(i);
		}
	}

	return points;
}

void AllEnemyShips::drawAllEnemyShips(sf::RenderWindow & gameWindow)
{
	for (int i = 0; i < currentShips.size(); i++)
	{
		gameWindow.draw(*currentShips.at(i));
	}
}

vector<Ships*> AllEnemyShips::getCurrentEnemyShips() const
{
	return currentShips;
}

vector<Ships*>& AllEnemyShips::getAndModifyCurrentEnemyShips()
{
	return currentShips;
}
