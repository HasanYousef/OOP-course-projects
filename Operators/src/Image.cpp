#pragma once
#include "Image.h"
#include <ostream>

//--------------------------------------------------
Image::Image(int H, int W) {
	m_height = (H >= 0) ? H : 0;
	m_width = (W >= 0) ? W : 0;
	m_datastruct = ImageDataStructure(H, W, WHITE);
}

//-------------------------------------------------
Image::Image(int H, int W, unsigned char pixel) {
	m_height = (H >= 0) ? H : 0;
	m_width = (W >= 0) ? W : 0;
	m_datastruct = ImageDataStructure(m_height, m_width, pixel);
}

//-------------------------------------------------
Image::~Image() {
	m_datastruct.free(m_height);
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
Pixel Image::operator()(unsigned int col, unsigned int row) const {
	return m_datastruct(col, row);
}

//------------------------------------------------
void Image::operator=(const Image& other) {
	//deleting the old image
	m_datastruct.free(m_height);
	m_height = other.get_height();
	m_width = other.get_width();
	//copying the image data
	m_datastruct = ImageDataStructure(other.m_datastruct, m_height, m_width);
}

//------------------------------------------------
Pixel& Image::operator()(unsigned int col, unsigned int row) {
	return m_datastruct(col, row);
}

//===========================================================//

//---Global---Operators----------------------------
//-------------------------------------------------
bool operator==(const Image& first, const Image& second)
{
	//if the 2 images dont have the same width or height then they are not equal
	if (first.get_width() != second.get_width() ||
		first.get_height() != second.get_height()) {
		return false;
	}
	//we check the pixels colors 
	for (int row = 0; row < second.get_height(); row++) {
		for (int col = 0; col < first.get_width(); col++) {
			if (first(col, row) != second(col, row)) {
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
	newimage = Image(image.get_height(), image.get_width());
	//for each pixel if the pixel black should be converted to white,
	//if white should be black and if it is gray it should be gray
	for (int row = 0; row < image.get_height(); row++) {
		for (int col = 0; col < image.get_width(); col++) {
			if (image(col, row) == WHITE) {
				newimage(col, row) = BLACK;
			}
			else if (image(col, row) == BLACK) {
				newimage(col, row) = WHITE;
			}
			else {
				newimage(col, row) = GRAY;
			}
		}
	}
	return newimage;
}

//--------------------------------------------------------
Image operator+(const Image& A, const Image& B)
{
	Image newimage(max(A.get_height(), B.get_height()),
		(A.get_width() + B.get_width()));
	//Copy A image
	for (int row = 0; row < A.get_height(); row++) {
		for (int col = 0; col < A.get_width(); col++) {
			newimage(col, row) = A(col, row);
		}
	}
	//Copy B image
	for (int row = 0; row < B.get_height(); row++) {
		for (int col = A.get_width(); col < newimage.get_width(); col++) {
			newimage(col, row) = B(col - A.get_width(), row);
		}
	}

	return newimage;
}

//--------------------------------------------------------
Image operator+=(Image& A, const Image& B) {
	A = A + B;
	return A;
}

//--------------------------------------------------------
Image operator*(const Image& image, int n)
{
	//multiplying an image by n is adding the same image n times
	int replay = 0;
	Image newimage(0, 0);
	while (replay < n) {
		newimage += image;
		replay++;
	}
	return newimage;
}

//--------------------------------------------------------
Image operator*(int n, const Image& image)
{
	return image * n;
}

//--------------------------------------------------------
Image operator*=(Image& image, int n) {
	//multiply the image then save it
	image = image * n;
	return image;
}

//--------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Image& image)
{
	//prints all the pixels in the givel image
	for (int row = 0; row < image.get_height(); row++) {
		for (int col = 0; col < image.get_width(); col++) {
			os << image(col, row);
		}
		os << std::endl;
	}
	return os;
}

Image operator&(const Image& left, const Image& right) {
	int minHeight = left.get_height() < right.get_height() ? left.get_height() : right.get_height(),
		minWidth = left.get_width() < right.get_width() ? left.get_width() : right.get_width();
	Image newImg(minHeight, minWidth);
	//running all over the new image pixels to set them
	for (int row = 0; row < minHeight; row++) {
		for (int col = 0; col < minWidth; col++) {
			newImg(col, row) = left(col, row) & right(col, row);
		}
	}
	return newImg;
}

Image operator|(const Image& left, const Image& right) {
	int leftHeight = left.get_height(),
		rightHeight = right.get_height(),
		leftWidth = left.get_width(),
		rightWidth = right.get_width();
	int maxHeight = rightHeight > leftWidth ? rightHeight : leftWidth,
		maxWidth = leftWidth > rightWidth ? leftWidth : rightWidth;
	//making a new image in the size of the max width and height
	Image newImg(maxHeight, maxWidth);

	//running all over the new image pixels to set them
	for (int row = 0; row < maxHeight; row++) {
		for (int col = 0; col < maxWidth; col++) {
			//if this is a mutual pixel
			if (row < leftHeight && row < rightHeight
				&& col < leftWidth && col < rightWidth)
				newImg(col, row) = left(col, row) | right(col, row);
			//if this is pixel exist in the left image
			else if (row < leftHeight && col < leftWidth)
				newImg(col, row) = left(col, row);
			//if this is pixel exist in the right image
			else if (row < rightHeight && col < rightHeight)
				newImg(col, row) = right(col, row);
		}
	}
	return newImg;
}

Image& operator|=(Image& left, const Image& right) {
	left = left | right;
	return left;
}

Image& operator&=(Image& left, const Image& right) {
	left = left & right;
	return left;
}
