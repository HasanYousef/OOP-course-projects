#pragma once

#include <iostream>

#include "Coord.h"

Coord& Coord::operator=(const Coord& other) {
	if (&other != this) {
		m_col = other.m_col;
		m_row = other.m_row;
	}
	return *this;
}

bool Coord::is_valid(int boardSize) const {
	return (m_col >= 0 && m_row >= 0
		&& m_col < boardSize && m_row < boardSize);
}

bool operator==(const Coord& l, const Coord& r) {
	return (l.m_col == r.m_col && l.m_row == r.m_row);
}

bool operator!=(const Coord& l, const Coord& r) {
	return !(l == r);
}