#pragma once

#include "Button.h"
#include "Textures.h"

class TextureButton : public Button {
public:
	ObjectType optionToObjectType() const;
	//----------------------------------------------
	virtual void draw(sf::RenderWindow& window) const;
};
