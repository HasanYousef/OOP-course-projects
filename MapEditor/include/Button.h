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
	bool handleClick(const sf::Vector2f) const;
	//------------------------------------------------------
	void setPosition(sf::Vector2f);
	//------------------------------------------------------
	sf::Vector2f getPosition() const;
protected:
	sf::RectangleShape m_button;
};
