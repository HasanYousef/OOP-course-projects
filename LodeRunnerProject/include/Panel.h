#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "macros.h"
#include "Button.h"
#include "Textures.h"
#include "TextButton.h"
#include "TextureButton.h"

class Panel {
public:
	Panel() {};
	//----------------------------------------------
	void addTextureButton(UserOption);
	void addTextButton(UserOption, std::string string);
	UserOption handle_click(const sf::Vector2f&) const;
	void draw(sf::RenderWindow&) const;
	void setPosition(sf::Vector2f);
	void clear();

private:
	std::vector<Button*> m_buttons;
	sf::Vector2f m_position;
};