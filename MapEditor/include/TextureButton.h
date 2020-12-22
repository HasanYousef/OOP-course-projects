#pragma once

#include "Button.h"

class TextureButton : public Button {
public:
	TextureButton(const sf::Texture*, const sf::Vector2f&, ObjectType);
	//----------------------------------------------
	void draw(sf::RenderWindow& window) const;
	ObjectType getType() const;
private:
	ObjectType m_type;
	const sf::Texture* m_texture;
};


