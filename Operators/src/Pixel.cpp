#pragma once
#include "Pixel.h"

#include <ostream>

// Pixel builder and converter from unsigned char to Pixel
Pixel::Pixel(unsigned char pixel) {
	// the color should be one of the 3
	if (pixel == WHITE || pixel == GRAY || pixel == BLACK)
		m_color = pixel;
}

unsigned char Pixel::get_color() const {
	return m_color;
}

// GLOBAL OPERATORS

bool operator==(const Pixel& left, const Pixel& right) {
	return (left.get_color() == right.get_color());
}

bool operator!=(const Pixel& left, const Pixel& right) {
	return !(left == right);
}

//is brighter
bool operator<(const Pixel& left, const Pixel& right) {
	return left.get_color() < right.get_color();
}

bool operator<=(const Pixel& left, const Pixel& right) {
	return (left < right || left == right);
}

//is darker
bool operator>(const Pixel& left, const Pixel& right) {
	return !(left <= right);
}

bool operator>=(const Pixel& left, const Pixel& right) {
	return !(left < right);
}

//print pixel
std::ostream& operator<<(std::ostream& os, const Pixel& pixel) {
	os << pixel.get_color();
	return os;
}
//will return the darker pixel
Pixel operator|(const Pixel& left, const Pixel& right) {
	return left >= right ? Pixel(left) : Pixel(right);
}

//will return the brighter pixel
Pixel operator&(const Pixel& left, const Pixel& right) {
	return left >= right ? Pixel(right) : Pixel(left);
}

Pixel& operator|=(Pixel& left, const Pixel& right) {
	left = left | right;
	return left;
}
Pixel& operator&=(Pixel& left, const Pixel& right) {
	left = left & right;
	return left;
}