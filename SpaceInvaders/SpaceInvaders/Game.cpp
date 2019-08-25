#include "Game.h"

Game::Game()
{
	//sf::RenderWindow gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "CPTS 122 Lab", sf::Style::Titlebar | sf::Style::Close);
	gameWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders", sf::Style::Titlebar | sf::Style::Close);
	gameWindow.setVerticalSyncEnabled(true); //matches frame rate of this to computer
	score = 0;
	scoreText.setString(itoa(score, scoreStr, 10)); // convert score to str and set the scoreText equal to the str
	font.loadFromFile("ComicSansMS3.ttf");
	scoreText.setPosition(10, 760);
	scoreText.setFont(font);
}

Game::~Game()
{

}

void Game::gameLoop()
{
	//testing objects
	AllEnemyShips allEnemies;
	FriendlyShip player;
	AllLasers allLasers;
	double frequencyEnemySpawning = 1;
	int laserCountDown = 0;
	long long counter = 0;
	bool goingLeft = false;
	bool goingRight = false;

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
				goingRight = true;
				goingLeft = false;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			{
				goingLeft = true;
				goingRight = false;
			}
			else
			{
				goingLeft = false;
				goingRight = false;
			}

			if (myevent.type == sf::Event::KeyPressed)
			{
				if (myevent.key.code == sf::Keyboard::Key::Space)
				{
					if (laserCountDown <= 0 && !allEnemies.checkIfShipDestroyed(player))
					{
						allLasers.spawnLaser(player);
						laserCountDown = 10;
					}
				}
			}

		}

		gameWindow.clear();

		//player movement
		if (goingLeft == true)
			player.movement(-10);
		else if (goingRight == true)
			player.movement(10);

		//spawning
		allEnemies.randomlySpawnNewEnemyShips(frequencyEnemySpawning);
		if(counter % 100 == 0) //insures non-constant shooting
			allLasers.spawnAllLasers(allEnemies.getCurrentEnemyShips());

		//move ships/lasers
		allEnemies.moveAllEnemyShips();
		allLasers.moveAllLasers();

		//delete out of bound ships/lasers
		allEnemies.deleteShipsOutOfBound();
		allLasers.deleteLasersOutOfBound();

		allLasers.checkIfShipCollisionWithAnyLaser(player); //checks if laser friendly ship collision
		allLasers.checkIfEnemyLaserCollision(allEnemies.getAndModifyCurrentEnemyShips()); //checks if any enemy ships have collisions with lasers
		allEnemies.checkIfShipCollisionWithAnyShip(player);

		//adds score
		//makes sure if player is dead they don't get points added to their score
		if(!allEnemies.checkIfShipDestroyed(player)) 
			score += allEnemies.checkIfEnemyShipsDestroyed();
		else
			allEnemies.checkIfEnemyShipsDestroyed();

		allEnemies.drawAllEnemyShips(gameWindow);
		allLasers.drawAllLasers(gameWindow);

		
		displayScore();

		if (allEnemies.checkIfShipDestroyed(player)) //if yes, player has no remaining health
		{
			std::cout << "You are dead!\n";
			std::cout << "Your score is: " << score << std::endl;
			break;
		}
		else
		{
			gameWindow.draw(player);
			player.displayHealth(gameWindow);
		}

		gameWindow.display();
		counter++;
		if (counter % 1000 == 0) //increases "level" (ie: enemy spawning frequency) every few cycles
		{
			std::cout << "Level " << (frequencyEnemySpawning - 1) * 10 + 1 << " completed. Moving to next level\n";
			frequencyEnemySpawning += .1;
		}
		if (laserCountDown > 0) //decrements laserCountDown
			laserCountDown--;
	}
}

void Game::displayScore()
{
	scoreText.setString(itoa(score, scoreStr, 10)); // update the score string and scoreText
	gameWindow.draw(scoreText); //display scoreText
}

void Game::run()
{
	Menu menu;

	int result = menu.menuLoop(gameWindow);

	if (result == 0)
	{
		gameLoop();
	}
	else
	{
		std::cout << "Exiting game." << std::endl;
	}
}
