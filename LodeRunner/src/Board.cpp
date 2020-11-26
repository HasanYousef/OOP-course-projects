#pragma once

#include "Board.h"

//-----------------structor-----------------
//the structor of the board will read from it first
//the size of the map that it gonna be read, then it will
//read all the map's chars line by line and store them
Board::Board(ifstream& mapStream) {
	//reading the size of the map that is gonna be read
	mapStream >> m_size;
	mapStream.get();
	//reading the map's chars line by line
	for (int row = 0; row <= m_size; row++) {
		string tempRow;
		getline(mapStream, tempRow);
		m_map.push_back(tempRow);
	}
}

//-----------------deep_copier-----------------
//it deep copy the given board
Board::Board(const Board& other) {
	m_size = other.get_size();
	for (int row = 0; row <= m_size; row++) {
		m_map.push_back(other.get_row(row));
	}
}

//-----------------deep_copier-----------------
//it deep copy the given board
string Board::get_row(int row) const {
	return(m_map[row]);
}

//-----------------print-----------------
//prints all the map in the console
void Board::print() const {
	//printing the map line by line
	for (int row = 0; row < m_size; row++)
		cout << m_map[row] << endl;
}

//-----------------get_char-----------------
//it takes a column and row indexes as integers and returns
//what char exists in the board with the same given indexes
char Board::get_char(const Coord& coord) const {
	//if one of the given indexes is out of the board return wall char
	if (!coord.is_valid(m_size))
		return WALL;
	return m_map[coord.m_row][coord.m_col];
}

//-----------------get_ground-----------------
Coord Board::get_ground(const Coord& coord) const {
	int h = 0;
	while (m_map[coord.m_row + h][coord.m_col] != WALL
		&& m_map[coord.m_row + h + 1][coord.m_col] != WALL 
		&& m_map[coord.m_row + h][coord.m_col] != LADDER 
		&& m_map[coord.m_row + h][coord.m_col] != ROPE)
		h++;
	return Coord(coord.m_col, coord.m_row + h);
}

//-----------------set_char-----------------
void Board::set_char(const Coord& coord, char ch) {
	m_map[coord.m_row][coord.m_col] = ch;
}

//-----------------get_size-----------------
//it returns the size of the board (LENGTHxLENGTH)
int Board::get_size() const {
	return m_size;
}
