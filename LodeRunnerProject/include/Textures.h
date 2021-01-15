#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "macros.h"

class Textures {
public:
	static Textures& instance();
	sf::Texture* get_texture(int) const;

private:
	Textures();

	std::vector<sf::Texture*> m_textures;
};