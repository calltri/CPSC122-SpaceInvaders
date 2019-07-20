#pragma once
#include"SFML/Graphics.hpp"
#include"Global_Constants.h"
#include <string.h>
using std::string;


class Ships : public sf::Sprite
{
public:
	//constructor
	Ships(string textureFile, float width, float length);
	//destructor
	~Ships();
	//movement
	virtual void movement();
	virtual void laserSpawn();


private:
	sf::Texture spriteTexture;
	int mHealth;


};