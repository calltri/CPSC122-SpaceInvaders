#include"SFML/Graphics.hpp"

int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(640, 800), "CPTS 122 Lab", sf::Style::Titlebar | sf::Style::Close);

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
		gameWindow.display();
	}
}