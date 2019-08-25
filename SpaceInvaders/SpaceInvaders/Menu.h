#pragma once
#include "Button.h"
#include <vector>
#include <iostream>

class Menu
{
public:
	Menu();
	~Menu();

	
	int menuLoop(sf::RenderWindow &window);
	void infoLoop(sf::RenderWindow &window);

private:

	

	bool isOpen;
	bool infoOpen;
	int currentButtonIndex;
	int numberOfButtons;
	sf::Texture backgroundTexture;
	sf::Texture infoTexture;
	sf::Sprite info;
	sf::Sprite background;
	std::vector<Button> buttons;
	sf::Font font;
};

