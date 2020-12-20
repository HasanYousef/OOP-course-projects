#pragma once

#include "Button.h"

class TextButton : Button {
public:
	TextButton(const std::string string, sf::Vector2f size, sf::Font&);
	void setPosition(sf::Vector2f);
protected:
	sf::Text m_text;
};
