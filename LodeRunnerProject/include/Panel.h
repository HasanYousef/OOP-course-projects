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
	void add_button(ObjectType);
	void add_button(std::string string);
	UserOption handle_click(const sf::Vector2f&) const;
	void draw(sf::RenderWindow&) const;

private:
	std::vector<Button*> m_buttons;
	sf::Vector2f m_position;
};