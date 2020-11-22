#pragma once
#include "Board.h"

//-----------------structor-----------------
//the structor of the board will read from it first
//the size of the map that it gonna be read, then it will
//read all the map's chars line by line and store them
Board::Board(ifstream& mapStream) {
	//reading the size of the map that is gonna be read
	mapStream >> m_size;
	//readin the map's chars line by line
	for (int row = 0; row < m_size; row++) {
		for (int col = 0; col < m_size; col++)
			mapStream.get(m_map[row][col]);
	}
}
//-----------------deep_copier-----------------
//it deep copy the given board
Board::Board(const Board& other) {
	m_size = other.m_size;
	for (int index = 0; index < other.m_map.size(); index++) {
		m_map[index] = other.m_map[index];
	}
}

//-----------------print-----------------
//prints all the map in the console
void Board::print() {
	//printing the map line by line
	for (int row = 0; row < m_size; row++) {
		for (int col = 0; col < m_size; col++)
			cout << m_map[row][col];
	}
}

//-----------------get_char-----------------
//it takes a column and row indexes as integers and returns
//what char exists in the board with the same given indexes
char Board::get_char(const Coord& coord) const {
	//if one of the given indexes is out of the board return wall char
	if (coord.m_col < 0 || coord.m_col >= m_size 
		|| coord.m_row < 0 || coord.m_row >= m_size)
		return WALL;
	return m_map[coord.m_col][coord.m_row];
}

//-----------------get_size-----------------
//it returns the size of the board (LENGTHxLENGTH)
int Board::get_size() const {
	return m_size;
}
