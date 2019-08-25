#include "Menu.h"



Menu::Menu()
{
	font.loadFromFile("ComicSansMS3.ttf");
	buttons.push_back(Button("Start", font, {280, 620 }, {80, 40 }));
	buttons.push_back(Button("Info", font, { 280, 680 }, { 80, 40 }));
	buttons.push_back(Button("Exit", font, { 280, 740 }, { 80, 40 }));
	buttons[0].enableOutline();
	currentButtonIndex = 0;
	numberOfButtons = 3;
	if (backgroundTexture.loadFromFile("MenuBG.png"))
	{
		background.setTexture(backgroundTexture);
	}
	else { std::cout << "failed to load bg texture." << std::endl; }

	if (infoTexture.loadFromFile("InfoBG.png"))
	{
		info.setTexture(infoTexture);
	}
	else { std::cout << "failed to load infobg texture." << std::endl; }


	infoOpen = false;
}


Menu::~Menu()
{
}


int Menu::menuLoop(sf::RenderWindow &window)
{
	this->isOpen = true;

	
	
while (this->isOpen)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				this->isOpen = false;
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Down)
				{
					if (currentButtonIndex != numberOfButtons - 1)
					{
						buttons[currentButtonIndex].disableOutline();
						currentButtonIndex++;
						buttons[currentButtonIndex].enableOutline();
					}
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					if (currentButtonIndex != 0)
						{
							buttons[currentButtonIndex].disableOutline();
							currentButtonIndex--;
							buttons[currentButtonIndex].enableOutline();
						}
				}
				if (event.key.code == sf::Keyboard::Enter)
				{
					if (currentButtonIndex == 1)
					{
						infoLoop(window);
					}
					else
					{
						return currentButtonIndex;
					}
				}
				break;
				
			}
		}

		window.clear();
		window.draw(background);
		for (Button button : buttons)
			window.draw(button);
		window.display();
	}

}

void Menu::infoLoop(sf::RenderWindow &window)
{
	this->infoOpen = true;

	
	
while (this->infoOpen)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Enter)
				{
					infoOpen = false;
				}
				break;
				
			}
		}

		window.clear();
		window.draw(info);
		window.display();
	}

}

