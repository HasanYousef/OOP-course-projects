#pragma once

#include "Board.h"

	// MAYBE THERE IS NO NEED FOR THIS
Board::Board() :
m_height(0), m_width(0) {}

Board::Board(int height, int width) :
m_height(height), m_width(width) {
	for (int row = 0; row <= m_height; row++) {
		std::vector<WorldObject> tempRow;
		for (int col = 0; col <= m_width; col++) {
			tempRow.push_back(WorldObject(ObjectType::Space,
				m_textures[ObjectType::Space],
				indexes_to_location(col,row)));
		}
		m_worldObjects.push_back(tempRow);
	}
}

Board::Board(std::ifstream& stream, int height = 0, int width = 0) :
m_height(height), m_width(width) {
	char ch;
	//reading the map's chars line by line
	for (int row = 0; row <= m_height; row++) {
		for (int col = 0; col <= m_width; col++) {
			ch = stream.get();
			/*m_worldObjects[row].push_back(WorldObject(
				charToType(ch),
				charToTexture(ch),
				indexesToLocation(col, row));*/
		}
	}
}

void Board::draw(sf::RenderWindow& window) const {
	for (int row = 0; row < m_height; row++)
		for (int col = 0; col < m_width; col++)
			m_worldObjects[row][col].draw(window);
}

sf::Vector2f Board::indexes_to_location(int col, int row) {

}

void Board::initializeTextures() {
	m_textures[NUM_OF_TYPES];
	m_textures[ObjectType::Space].loadFromFile("space.png");
	m_textures[ObjectType::Wall].loadFromFile("wall.png");
	m_textures[ObjectType::Ladder].loadFromFile("ladder.png");
	m_textures[ObjectType::Rope].loadFromFile("rope.png");
	m_textures[ObjectType::Money].loadFromFile("money.png");
	m_textures[ObjectType::Player].loadFromFile("player.png");
	m_textures[ObjectType::Enemy].loadFromFile("enemy.png");
}