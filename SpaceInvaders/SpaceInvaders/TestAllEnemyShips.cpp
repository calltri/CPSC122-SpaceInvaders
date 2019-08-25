#include"TestAllEnemyShips.h"

void TestAllEnemyShips::TestRandomlySpawnNewEnemyShips()
{
	for (int i = 0; i < 1000; i++)
	{
		randomlySpawnNewEnemyShips();
	}


	sf::RenderWindow gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "CPTS 122 Lab", sf::Style::Titlebar | sf::Style::Close);

	gameWindow.setVerticalSyncEnabled(true); //matches frame rate of this to computer

	while (gameWindow.isOpen())
	{
		sf::Event myevent;

		while (gameWindow.pollEvent(myevent))
		{
			if (myevent.type == sf::Event::Closed)
				gameWindow.close();
		}

		gameWindow.clear();
		
		drawAllEnemyShips(gameWindow);


		gameWindow.display();
	}
}

void TestAllEnemyShips::TestShipMovement()
{
	currentShips.push_back(new BasicEnemy);
	currentShips.push_back(new Enemy2);
	currentShips.push_back(new EnemyBoss);

	sf::RenderWindow gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "CPTS 122 Lab", sf::Style::Titlebar | sf::Style::Close);

	gameWindow.setVerticalSyncEnabled(true); //matches frame rate of this to computer

	while (gameWindow.isOpen())
	{
		sf::Event myevent;

		while (gameWindow.pollEvent(myevent))
		{
			if (myevent.type == sf::Event::Closed)
				gameWindow.close();
		}

		gameWindow.clear();

		moveAllEnemyShips();
		deleteShipsOutOfBound();
		drawAllEnemyShips(gameWindow);


		gameWindow.display();
	}
}

void TestAllEnemyShips::TestLaserCollision()
{
	sf::RenderWindow gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders", sf::Style::Titlebar | sf::Style::Close);
	gameWindow.setVerticalSyncEnabled(true);
	AllEnemyShips allEnemies;
	FriendlyShip player;
	AllLasers allLasers;
	//end testing objects
	while (gameWindow.isOpen())
	{
		sf::Event myevent;

		while (gameWindow.pollEvent(myevent))
		{
			if (myevent.type == sf::Event::Closed)
				gameWindow.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			{
				player.movement(3);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			{
				player.movement(-3);
			}
			if (myevent.type == sf::Event::KeyPressed)
			{
				if (myevent.key.code == sf::Keyboard::Key::Space)
				{
					allLasers.spawnLaser(player);
				}
			}

		}

		gameWindow.clear();

		//spawning
		allEnemies.randomlySpawnNewEnemyShips(3);
		//allLasers.spawnAllLasers(allEnemies.getCurrentEnemyShips());

		//move ships/lasers
		allLasers.moveAllLasers();

		allLasers.checkIfShipCollisionWithAnyLaser(player); //checks if laser friendly ship collision
		allLasers.checkIfEnemyLaserCollision(allEnemies.getAndModifyCurrentEnemyShips()); //checks if any enemy ships have collisions with lasers
		allEnemies.checkIfShipCollisionWithAnyShip(player);

		allEnemies.checkIfEnemyShipsDestroyed();

		allEnemies.drawAllEnemyShips(gameWindow);
		allLasers.drawAllLasers(gameWindow);

		gameWindow.draw(player);


		gameWindow.display();
	}
}

