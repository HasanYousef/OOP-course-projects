#pragma once

#include "Button.h"

class TextButton : public Button {
public:
	TextButton(const std::string&, const sf::Vector2f&, const sf::Font&);
	//----------------------------------------------
	void draw(sf::RenderWindow& window) const;
private:
	std::string m_text;
	sf::Font m_font;
};
