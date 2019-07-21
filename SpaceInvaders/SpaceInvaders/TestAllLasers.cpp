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

		moveAllLasers(currentLasers);
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
		moveAllLasers(currentLasers);
		for (int i = 0; i < currentLasers.size(); i++)
		{
			gameWindow.draw(*currentLasers.at(i));
		}
		
		gameWindow.display();
	}
}
