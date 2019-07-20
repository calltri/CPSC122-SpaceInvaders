/*******************************************************************************
 * Programmer: Tristan Call, Dominic Davok, Chandler Teigen                                                    *
 * Class: CptS 122; Lab Section 1                                              *
 * Programming Assignment: PA8                                                 *
 * Date: 7-19-19                                                               *
 *                                                                             *
 * Description: space invaders
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record in input file:none
                                            *
 * Format of output file:none
 ******************************************************************************/


#include"SFML/Graphics.hpp"
#include"Lasers.h"
#include"Global_Constants.h"


int main()
{
	
	Lasers l1(*(new sf::Vector2f(30,30))); //test laser
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
		gameWindow.draw(l1);
		gameWindow.display();
	}
}