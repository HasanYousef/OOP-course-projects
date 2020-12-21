#pragma once

#include "Button.h"

class TextButton : Button {
public:
	TextButton(const std::string& string, const sf::Vector2f& size, const sf::Font&);
	void setPosition(sf::Vector2f);
	std::string getType() const;
protected:
	sf::Text m_text;
};
