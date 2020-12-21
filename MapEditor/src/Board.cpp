#pragma once

#include "Board.h"

Board::Board() :
	m_height(0), m_width(0) {
	initializeTextures();
}

Board::Board(int height = 0, int width = 0) {
	setNew(height, width);
	initializeTextures();
}

void Board::readFromStream(std::ifstream& stream) {
	int row = 0,
		col = 0;
	std::vector<std::vector<WorldObject>> newBoard;
	ObjectType type;
	char ch;
	//reading the map's chars line by line
	ch = stream.get();
	while (true) {
		std::vector<WorldObject> tempRow;
		col = 0;
		while (ch != '\n' && !stream.eof()) {
			type = charToType(ch);
			tempRow.push_back(WorldObject(
				type,
				m_textures[type],
				sf::Vector2f(col * TEXTURE_SIZE + BOARD_UI_X, row * TEXTURE_SIZE)
			));
			col++;
			ch = stream.get();
		}
		newBoard.push_back(tempRow);
		if (stream.eof())
			break;
		row++;
		ch = stream.get();
	}
	m_worldObjects = newBoard;
	m_height = m_worldObjects.size();
	m_width = (m_height > 0 ? m_worldObjects[0].size() : 0);
}

void Board::draw(sf::RenderWindow& window) const {
	for (int row = 0; row < m_height; row++)
		for (int col = 0; col < m_width; col++)
			m_worldObjects[row][col].draw(window);
}

void Board::setNew(int height, int width) {
	m_height = height;
	m_width = width;
	std::vector<std::vector<WorldObject>> newBoard;
	for (int row = 0; row <= m_height; row++) {
		std::vector<WorldObject> tempRow;
		for (int col = 0; col <= m_width; col++) {
			tempRow.push_back(WorldObject(ObjectType::Space,
				m_textures[ObjectType::Space],
				sf::Vector2f(col * TEXTURE_SIZE + BOARD_UI_X, row * TEXTURE_SIZE)));
		}
		newBoard.push_back(tempRow);
	}
	m_worldObjects = newBoard;
}

void Board::set_object(ObjectType type, const sf::Vector2f& location) {
	int col = int(location.x - BOARD_UI_X) / TEXTURE_SIZE;
	int row = int(location.y) / TEXTURE_SIZE;
	m_worldObjects[row][col] = WorldObject(type, m_textures[int(type)], sf::Vector2f(col, row));
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

ObjectType Board::charToType(char ch) {
	switch (ch) {
	case SPACE:
		return ObjectType::Space;
	case WALL:
		return ObjectType::Wall;
	case LADDER:
		return ObjectType::Ladder;
	case ROPE:
		return ObjectType::Rope;
	case MONEY:
		return ObjectType::Money;
	case PLAYER:
		return ObjectType::Player;
	case ENEMY:
		return ObjectType::Enemy;
	}
}