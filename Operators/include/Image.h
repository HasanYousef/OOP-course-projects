#pragma once

#include "Pixel.h"
#include "Macros.h"
#include "ImageDataStructure.h"


#include <minmax.h>

class Image {
public:
	//---Constructors--------------------
	Image();
	Image(int, int);
	Image(int, int, unsigned char pixel);
	Image(const Image&);
	//---Functions----------------------
	int get_height() const;
	int get_width() const;

	//---Local---operators--------------
	Pixel operator()(unsigned int, unsigned int) const;
	Pixel& operator()(unsigned int, unsigned int);
	void operator=(const Image&);

private:
	int m_height, m_width;
	ImageDataStructure m_datastruct;
};

//---globals operators------------------------------------
//--------------------------------------------------------
bool operator==(const Image& first, const Image& second);
bool operator!=(const Image& first, const Image& second);
Image operator~(const Image& image);
Image operator+(const Image& A, const Image& B);
Image operator+=(const Image& A, const Image& B);
Image operator*(const Image& image, int n);
Image operator*=(const Image& image, int n);
std::ostream& operator<<(std::ostream& os, const Image& image);

