/*******************************************************************************
 * Programmer: Tristan Call, Dominic Davok, Chandler Teigen                    *
 * Class: CptS 122; Lab Section 1                                              *
 * Programming Assignment: PA8                                                 *
 * Date: 7-19-19                                                               *
 *                                                                             *
 * Description: space invaders												   *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record in input file:none										   *	
 *																			   *
 * Format of output file:none												   *
 ******************************************************************************/


#include"SFML/Graphics.hpp"
#include"Lasers.h"
#include"GoodLaser.h"
#include"Global_Constants.h"
#include "Ships.h"
#include "BasicEnemy.h"
#include <vector>
#include"TestAllLasers.h"
#include<ctime>
#include<cstdlib>

using std::vector;

int main()
{
	TestAllLasers test1;
	srand(time(0));

	//test1.TestSpawnAllLasers();
	//test1.TestMoveAllLasers();
	/*
	BasicEnemy e1; //test ship with test texture
	e1.setPosition(*(new sf::Vector2f(100, 100)));
	
	vector<Lasers*> currentLasers;
	currentLasers.push_back(new Lasers(*(new sf::Vector2f(600, 400))));
	currentLasers.push_back(new GoodLaser(*(new sf::Vector2f(10, 600))));
	static_cast<GoodLaser*>(currentLasers.at(0));

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


		for (int i = 0; i < currentLasers.size(); i++)
		{
			static_cast<GoodLaser*>(currentLasers.at(i))->moveLaser();
			gameWindow.draw(*currentLasers.at(i));
		}
		gameWindow.draw(e1);
		gameWindow.display();
	}
	*/
}
