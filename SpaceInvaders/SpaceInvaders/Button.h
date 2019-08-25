#pragma once
#include "SFML/Graphics.hpp"



class Button : public sf::Drawable

{
public:
	Button(sf::String text, sf::Font &font, sf::Vector2f pos = { 0,0 }, sf::Vector2f dim = { 100, 200 });
	~Button();

	void enableOutline();

	void disableOutline();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:

	sf::RectangleShape buttonShape;
	sf::Text buttonText;
	

};

