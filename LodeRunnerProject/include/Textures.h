#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "macros.h"

class Textures {
public:
	static Textures& instance();
	sf::Texture* get_texture(ObjectType) const;

private:
	Textures();

	sf::Texture* m_textures[NUM_OF_TYPES];
};