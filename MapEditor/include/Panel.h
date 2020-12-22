#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"
#include "TextButton.h"
#include "TextureButton.h"

class Panel {
public:
	Panel() {};
	//----------------------------------------------
	void initPanel(sf::Texture* []);
	ActionType handleClick(const sf::Vector2f&) const;
	void draw(sf::RenderWindow&) const;

private:
	std::vector<TextureButton> m_textureButtons;
	std::vector<TextButton> m_textButtons;
	sf::Font m_font;
};