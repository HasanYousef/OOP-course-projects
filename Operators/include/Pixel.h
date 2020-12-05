#pragma once

#include <iosfwd>
#include "Macros.h"

class Pixel {
public:
	Pixel(unsigned char pixel = BLACK);
	unsigned char get_color() const;

private:
	unsigned char m_color = unsigned char();
};

// GLOBAL OPERATORS

bool operator==(const Pixel&, const Pixel&);
bool operator!=(const Pixel&, const Pixel&);
bool operator<(const Pixel&, const Pixel&);				//is smaller
bool operator<=(const Pixel&, const Pixel&);
bool operator>(const Pixel&, const Pixel&);				//is bigger
bool operator>=(const Pixel&, const Pixel&);
std::ostream& operator<<(std::ostream&, const Pixel&);	//print pixel
Pixel operator|(const Pixel&, const Pixel&);			//pick darker
Pixel operator&(const Pixel&, const Pixel&);			//pick brighter;
Pixel& operator|=(Pixel&, const Pixel&);				//pick darker
Pixel& operator&=(Pixel&, const Pixel&);				//pick brighter