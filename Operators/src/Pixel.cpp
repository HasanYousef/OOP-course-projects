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

Pixel& Pixel::operator=(const Pixel& right) {
	m_color = right.get_color();
	return *this;
}

//??????????????????????????????????????????????????????????????????///
Pixel& Pixel::operator|=(const Pixel& right) {
	*this = (*this | right);
	return *this;
}
Pixel& Pixel::operator&=(const Pixel & right) {
	*this = (*this & right);
	return *this;
}

// GLOBAL OPERATORS

bool operator==(const Pixel& left, const Pixel& right) {
	return (left.get_color() == right.get_color());
}

bool operator!=(const Pixel& left, const Pixel& right) {
	return !(left == right);
}

bool operator<(const Pixel& left, const Pixel& right) {
	return left.get_color() < right.get_color();
}

bool operator<=(const Pixel& left, const Pixel& right) {
	return (left < right || left == right);
}

bool operator>(const Pixel& left, const Pixel& right) {
	return !(left <= right);
}

bool operator>=(const Pixel& left, const Pixel& right) {
	return !(left < right);
}

std::ostream& operator<<(std::ostream& os, const Pixel& pixel) {
	os << pixel.get_color();
	return os;
}

Pixel operator|(const Pixel& left, const Pixel& right) {
	return left >= right ? Pixel(left) : Pixel(right);
}

Pixel operator&(const Pixel& left, const Pixel& right) {
	return left >= right ? Pixel(right) : Pixel(left);
}
