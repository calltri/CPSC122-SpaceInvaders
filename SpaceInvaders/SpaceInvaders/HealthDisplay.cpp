#include "HealthDisplay.h"



HealthDisplay::HealthDisplay(string textureFile, float width, float length) : Sprite()
{
	spriteTexture.loadFromFile(textureFile);
	this->setTexture(spriteTexture);
}


HealthDisplay::~HealthDisplay()
{

}
