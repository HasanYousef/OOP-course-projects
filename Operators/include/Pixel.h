#pragma once

#include <iosfwd>
#include "Macros.h"

class Pixel {
public:
	Pixel(unsigned char pixel = ' ');
	unsigned char get_color() const;

	Pixel& operator=|(const Pixel&);

private:
	const unsigned char m_color;
};

// GLOBAL OPERATORS

bool operator==(const Pixel&, const Pixel&);
bool operator!=(const Pixel&, const Pixel&);
bool operator<(const Pixel&, const Pixel&;
bool operator<=(const Pixel&, const Pixel&);
bool operator>(const Pixel&, const Pixel&);
bool operator>=(const Pixel&, const Pixel&);
std::ostream& operator<<(std::ostream&, const Pixel&);
Pixel operator|(const Pixel&, const Pixel&);
Pixel operator&(const Pixel&, const Pixel&);