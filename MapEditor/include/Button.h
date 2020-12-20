#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"

class Button {
public:
	Button() {}
	//------------------------------------------------------
	Button(sf::Vector2f);
	//------------------------------------------------------
	void draw(sf::RenderWindow&);
	//------------------------------------------------------
	bool isMouse(sf::RenderWindow& ,const sf::Event::MouseButtonEvent&);
	//------------------------------------------------------
	void setPosition(sf::Vector2f);
	//------------------------------------------------------
	sf::Vector2f getPosition() const;
	//------------------------------------------------------
	//void setPosition(sf::Vector2f);
protected:
	sf::RectangleShape m_button;
};
