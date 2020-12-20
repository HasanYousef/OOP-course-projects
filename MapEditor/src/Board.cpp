#pragma once

#include "Board.h"

Board::Board() :
m_height(0), m_width(0) {}

Board::Board(int height, int width) :
m_height(height), m_width(width) {
	std::String line;
	for (int col = 0; col < m_width, col++)
		line += SPACE;
	for (int row = 0; row < m_height, row++)
		m_worldObjects.push_back(line);
}

Board::Board(ifstream& mapStream, int height, int width) :
m_height(height), m_width(width) {
	//reading the map's chars line by line
	for (int row = 0; row <= m_size; row++) {
		string tempRow;
		getline(mapStream, tempRow);
		m_worldObjects.push_back(tempRow);
	}
}