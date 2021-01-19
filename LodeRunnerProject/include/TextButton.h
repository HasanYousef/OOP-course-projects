#pragma once

#include "Button.h"

class TextButton : public Button {
public:
	TextButton();
	TextButton(const std::string&, const sf::Vector2f&);
	//----------------------------------------------
	virtual void draw(sf::RenderWindow& window) const;
	void set_string(std::string string);
private:
	std::string m_string;
};
