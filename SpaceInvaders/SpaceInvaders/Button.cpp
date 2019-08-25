#include "Button.h"



Button::Button(sf::String text, sf::Font &font, sf::Vector2f pos, sf::Vector2f dim)
{
	
	buttonShape.setFillColor(sf::Color::Black);
	buttonShape.setSize(dim);
	buttonShape.setPosition(pos);
	buttonShape.setOutlineThickness(5);
	buttonShape.setOutlineColor(sf::Color::Black);

	buttonText.setString(text);
	buttonText.setFillColor(sf::Color::White);
	buttonText.setPosition(pos);
	buttonText.setFont(font);
}


Button::~Button()
{
}

void Button::enableOutline()
{
	buttonShape.setOutlineColor(sf::Color::Green);
}

void Button::disableOutline()
{
	buttonShape.setOutlineColor(sf::Color::Black);
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(buttonShape, states);
	target.draw(buttonText, states);
}
