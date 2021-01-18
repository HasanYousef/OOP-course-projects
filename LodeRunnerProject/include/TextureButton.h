#pragma once

#include "Button.h"
#include "Textures.h"

class TextureButton : public Button {
public:
	TextureButton();
	TextureButton(const sf::Vector2f&, ObjectType);
	//----------------------------------------------
	void draw(sf::RenderWindow& window) const;
	ObjectType getType() const;
	void set_type(ObjectType type);
private:
	ObjectType m_type;
};
