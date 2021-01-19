#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"
#include "Textures.h"
//----------------------------------
class Button {
public:
	Button();
	sf::RectangleShape create() const;
	UserOption handle_click(const sf::Vector2f location) const;
	sf::Vector2f get_position() const;
	void set_position(sf::Vector2f);
	void setOption(UserOption);
	virtual void draw(sf::RenderWindow& window) const = 0;
protected:
	UserOption m_option;
	sf::Vector2f m_position;
};
