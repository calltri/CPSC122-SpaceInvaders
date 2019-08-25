#pragma once
#include "Global_Constants.h"
#include "SFML/Graphics.hpp"
using std::string;

class HealthDisplay : public sf::Sprite
{
public:
	HealthDisplay(string textureFile = "heartSprite.png", float width = HEALTH_WIDTH, float length = HEALTH_HEIGHT);
	~HealthDisplay();

private:
	sf::Texture spriteTexture;
};

