#pragma once

#include <iosfwd>
#include "Macros.h"

class Pixel {
public:
	Pixel(unsigned char pixel = ' ');
	unsigned char get_color() const;

private:
	unsigned char m_color = unsigned char();
};

// GLOBAL OPERATORS

bool operator==(const Pixel&, const Pixel&);
bool operator!=(const Pixel&, const Pixel&);
bool operator<(const Pixel&, const Pixel&);
bool operator<=(const Pixel&, const Pixel&);
bool operator>(const Pixel&, const Pixel&);
bool operator>=(const Pixel&, const Pixel&);
std::ostream& operator<<(std::ostream&, const Pixel&);
Pixel operator|(const Pixel&, const Pixel&);
Pixel operator&(const Pixel&, const Pixel&);
Pixel& operator|=(Pixel&, const Pixel&);
Pixel& operator&=(Pixel&, const Pixel&);