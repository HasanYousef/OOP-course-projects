#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "macros.h"
#include "Button.h"

class Panel {
public:
	Panel() {};
	//----------------------------------------------
	void initPanel(sf::Texture* []);
	UserOption handleClick(const sf::Vector2f&) const;
	void draw(sf::RenderWindow&) const;

private:
	std::vector<Button> m_textureButtons;
	sf::Font m_font;
};