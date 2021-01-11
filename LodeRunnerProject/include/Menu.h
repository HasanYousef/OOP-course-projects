#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Button.h"
#include "macros.h"

class Menu {
public:
	Menu() {};
	//----------------------------------------------
	void initMenu(sf::Texture* []);
	UserOption handleClick(const sf::Vector2f&) const;
	void draw(sf::RenderWindow&) const;

private:
	std::vector<Button> m_textureButtons;
};
