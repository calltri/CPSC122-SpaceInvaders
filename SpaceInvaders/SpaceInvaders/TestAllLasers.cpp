#include"TestAllLasers.h"

void TestAllLasers::TestMoveAllLasers()
{
	currentLasers.push_back(new Lasers(*(new sf::Vector2f(100, 400))));
	currentLasers.push_back(new Lasers(*(new sf::Vector2f(200, 400))));
	currentLasers.push_back(new GoodLaser(*(new sf::Vector2f(500, 400))));
	currentLasers.push_back(new GoodLaser(*(new sf::Vector2f(600, 400))));

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

		moveAllLasers();
		for (int i = 0; i < currentLasers.size(); i++)
		{
			gameWindow.draw(*currentLasers.at(i));
		}
		gameWindow.display();
	}
}

void TestAllLasers::TestSpawnAllLasers()
{
	vector<Ships*> allShips;
	allShips.push_back(new BasicEnemy);
	allShips.push_back(new BasicEnemy);
	allShips.push_back(new BasicEnemy);
	allShips.push_back(new EnemyBoss);
	spawnAllLasers(allShips);

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



		gameWindow.draw(*allShips.at(0));
		gameWindow.draw(*allShips.at(1));
		gameWindow.draw(*allShips.at(2));
		gameWindow.draw(*allShips.at(3));
		moveAllLasers();
		for (int i = 0; i < currentLasers.size(); i++)
		{
			gameWindow.draw(*currentLasers.at(i));
		}
		
		gameWindow.display();
	}
}

void TestAllLasers::TestDeleteLasersOutOfBound()
{
	currentLasers.push_back(new Lasers(*(new sf::Vector2f(100, 400))));
	currentLasers.push_back(new Lasers(*(new sf::Vector2f(200, 400))));
	currentLasers.push_back(new GoodLaser(*(new sf::Vector2f(500, 400))));
	currentLasers.push_back(new GoodLaser(*(new sf::Vector2f(600, 400))));

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

		moveAllLasers();
		deleteLasersOutOfBound();
		if (currentLasers.empty())
		{
			std::cout << "Vector is now Empty\n"; //this should print at the time all lasers go out of bounds
		}
		for (int i = 0; i < currentLasers.size(); i++)
		{
			gameWindow.draw(*currentLasers.at(i));
		}
		gameWindow.display();
	}
}

void TestAllLasers::TestCheckIfCollision()
{
	currentLasers.push_back(new Lasers(*(new sf::Vector2f(500, 100 - LASER_HEIGHT - 1)))); //puts laser at top enemy ship
	currentLasers.push_back(new Lasers(*(new sf::Vector2f(500 - LASER_WIDTH - 1, 100)))); //puts laser to left enemy ship
	currentLasers.push_back(new Lasers(*(new sf::Vector2f(500 + ENEMY_SHIP_WIDTH + 1, 100)))); //puts laser to right enemy ship
	currentLasers.push_back(new Lasers(*(new sf::Vector2f(500, 100 + ENEMY_SHIP_HEIGHT + 1)))); //puts laser below enemy ship
	currentLasers.push_back(new Lasers(*(new sf::Vector2f(520, 100))));
	vector<Ships*> allShips;
	allShips.push_back(new BasicEnemy);
	allShips.at(0)->setPosition(*(new sf::Vector2f(500, 100)));


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

		for (int i = 0; i < allShips.size(); i++)
		{
			gameWindow.draw(*allShips.at(i));
		}
		drawAllLasers(gameWindow);
		gameWindow.display();
	}
	for (int i = 0; i < allShips.size(); i++)
	{
		for (int j = 0; j < currentLasers.size(); j++)
		{
			if (checkIfCollision(*allShips.at(i), *currentLasers.at(j)))
				std::cout << "Collision between ship " << i + 1 << " and laser " << j + 1 << "\n";
		}
	} //only laser 5 should have a collision

}

void TestAllLasers::TestIfSpawningGeneratesCollision()
{
	vector<Ships*> allShips;
	allShips.push_back(new EnemyBoss);

	spawnAllLasers(allShips);

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



		gameWindow.draw(*allShips.at(0));

		drawAllLasers(gameWindow);

		if (checkIfCollision(*allShips.at(0), *currentLasers.at(0)))
			std::cout << "Instant impact\n";
		if (checkIfCollision(*allShips.at(0), *currentLasers.at(1)))
			std::cout << "Instant impact\n";
		if (checkIfCollision(*allShips.at(0), *currentLasers.at(2)))
			std::cout << "Instant impact\n";
		gameWindow.display();
	}
}


