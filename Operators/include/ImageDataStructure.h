#pragma once


#include "Pixel.h"
#include "Macros.h"

#include <minmax.h>

class ImageDataStructure {
public:
	ImageDataStructure(int = 0, int = 0, unsigned char = WHITE);
	ImageDataStructure(const ImageDataStructure&, int, int);
	Pixel operator()(unsigned int, unsigned int) const;
	Pixel& operator()(unsigned int, unsigned int);
	void free(int);
private:
	Pixel** m_arr;
};

