#pragma once
#include "Global_Constants.h"
#include "SFML/Graphics.hpp"
#include "AllEnemyShips.h"
#include "AllLasers.h"
#include "FriendlyShip.h"
#include "BasicEnemy.h"
#include "Enemy2.h"
#include "EnemyBoss.h"
#include "HealthDisplay.h"
#include "Menu.h"

class Game
{
public:
	Game();
	~Game();

	/****************************************************************
	* Function: run												    *
	* Date Created: 7-22-19											*
	* Date Last Modified: 7-22-19									*
	* Description: runs the application
	* Input parameters: void	        *
	* Returns: void													*
	* Preconditions:  window open									*
	* Postconditions:	none										*
	*****************************************************************/
	void run();
	/****************************************************************
* Function: gameLoop										    *
* Date Created: 7-22-19											*
* Date Last Modified: 7-22-19									*
* Description: runs the event loop and logic loop of the game.
* Input parameters: void								        *
* Returns: void													*
* Preconditions:  window open									*
* Postconditions:	none										*
*****************************************************************/
	void gameLoop();
	/****************************************************************
	* Function: displayScore										    *
	* Date Created: 7-22-19											*
	* Date Last Modified: 7-22-19									*
	* Description: displays the score to the screen
	* Input parameters: none								        *
	* Returns: void													*
	* Preconditions:  window open									*
	* Postconditions:	none										*
	*****************************************************************/
	void displayScore();

private:
	sf::RenderWindow gameWindow;
	int score;
	sf::Text scoreText;
	char scoreStr[20];
	sf::Font font;

};



