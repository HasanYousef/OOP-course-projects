#pragma once

#include "Board.h"

Board::Board() :
m_height(0), m_width(0) {}

Board::Board(int height = 0, int width = 0) :
m_height(height), m_width(width) {
	std::String line;
	for (int col = 0; col < m_width, col++)
		line += SPACE;
	for (int row = 0; row < m_height, row++)
		m_worldObjects.push_back(line);
}

Board::Board(ifstream& stream = nullptr, int height = 0, int width = 0) :
m_height(height), m_width(width) {
	char ch;
	//reading the map's chars line by line
	for (int row = 0; row <= m_size; row++) {
		for (int col = 0; col <= m_size; col++) {
			stream.get(ch);
			m_worldObjects[row].push_back(WorldObject(
				charToType(ch),
				charToTexture(ch),
				indexesToLocation(col, row));
		}
	}
}

void Board::initializeTextures() {
	m_textures[NUM_OF_TYPES];
	m_textures[ObjectType::Wall].loadFromFile("wall.png");
	m_textures[ObjectType::Ladder].loadFromFile("ladder.png");
	m_textures[ObjectType::Rope].loadFromFile("rope.png");
	m_textures[ObjectType::Money].loadFromFile("money.png");
	m_textures[ObjectType::Player].loadFromFile("player.png");
	m_textures[ObjectType::Enemy].loadFromFile("enemy.png");
}