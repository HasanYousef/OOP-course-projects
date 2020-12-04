#pragma once
#include "Image.h"
#include "ImageDataStructure.cpp"

//--------------------------------------------------
Image::Image(int H, int W) {
	m_height = (H >= 0) ? H : 0;
	m_width = (W >= 0) ? W : 0;
	m_pixelColor = WHITE;
	m_datastruct = ImageDataStructure(H, W, WHITE);
}

//-------------------------------------------------
Image::Image(int H, int W, unsigned char pixel) {
	m_height = (H >= 0) ? H : 0;
	m_width = (W >= 0) ? W : 0;
	m_pixelColor = pixel;	
	m_datastruct = ImageDataStructure(H, W, WHITE);
}

//-------------------------------------------------
Image::Image(const Image& other) {
	*this = other;
}

//-------------------------------------------------
int Image::get_height() const {
	return m_height;
}

//-------------------------------------------------
int Image::get_width() const {
	return m_width;
}

//---Local---Operators-----------------------------
//-------------------------------------------------
unsigned int Image::operator()(int row, int col) const {
	return m_datastruct(row, col);
}

//------------------------------------------------
void Image::operator=(const Image& other) {
	m_datastruct.free(m_height);
	m_height = other.get_height();
	m_width = other.get_width();
	m_pixelColor = other.m_pixelColor;
	m_datastruct = ImageDataStructure(
		           m_height, m_width, m_pixelColor);
}

//------------------------------------------------
int unsigned& Image::operator()(int row, int col) {
	return m_datastruct(row, col);
}

//===========================================================//

//---Global---Operators----------------------------
//-------------------------------------------------
bool operator==(const Image& first, const Image& second)
{
	if (first.get_width() != second.get_width() ||
		first.get_height() != second.get_height()){
		return false;
	}
	//we check the pixels colors 
	for (int row = 0; row < second.get_height(); row++) {
		for (int col = 0; col < first.get_width(); col++) {
			if (first(row,col) != second(row, col)) {
				return false;
			}
		}
	}
	return true;
}

//-------------------------------------------------
bool operator!=(const Image& first, const Image& second) {
	return !(first == second);
}

//-------------------------------------------------
Image operator~(const Image& image) {
	Image newimage;
	newimage(image.get_height(), image.get_width());
	for (int row = 0; row < image.get_height(); row++) {
		for (int col = 0; col < image.get_width(); col++) {
			if (image(row, col) == WHITE) {
				newimage(row, col) = BLACK;
			}
			else if (image(row, col) == BLACK) {
				newimage(row, col) = WHITE;
			}
		}
	}
	return newimage;
}

//--------------------------------------------------------
Image operator+(const Image& A, const Image& B)
{
	Image newimage(max(A.get_height(), B.get_height()),
		A.get_width() + B.get_width());
	//Copy A image
	for (int row = 0; row < A.get_height(); row++) {
		for (int col = 0; col < A.get_width(); col++) {
			newimage(row, col) = A(row, col);
		}
	}
	//Copy B image
	for (int row = 0; row < B.get_height(); row++) {
		for (int col = A.get_width(); col < B.get_width(); col++) {
			newimage(row, col) = B(row, col);
		}
	}
	//WHITE pixels
	if (A.get_height() > B.get_height()) {
		for (int row = B.get_height(); row < A.get_height(); row++) {
			for (int col = A.get_width(); col < B.get_width() + A.get_width(); col++) {
				newimage(row, col) = B(row, col);
			}
		}
	}
	else {
		for (int row = B.get_height(); row < newimage.get_height(); row++) {
			for (int col = 0; col < B.get_width(); col++) {
				newimage(row, col) = B(row, col);
			}
		}
	}
	return newimage;
}

//--------------------------------------------------------
Image operator+=(const Image& A, const Image& B) {
	return (A + B);
}

//--------------------------------------------------------
Image operator*(const Image& image, int n)
{
	int replay = 0;
	Image newimage(image.get_height(), image.get_width());
	while (replay < n) {
		newimage += image;
		replay++;
	}
	return newimage;
}

//--------------------------------------------------------
Image operator*=(const Image& image, int n) {
	return image * n;
}

//--------------------------------------------------------



