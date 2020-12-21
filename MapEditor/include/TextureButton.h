#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"
#include "Button.h"

class TextureButton : public Button {
public:
	TextureButton(const sf::Texture&, const sf::Vector2f&, ObjectType);
	ObjectType getType() const;

private:
	ObjectType m_type;
};


