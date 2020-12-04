#pragma once

#include <iostream>
#include "ImageDataStructure.h"

//--------------------------------------------------
ImageDataStructure::ImageDataStructure(int H, int W, unsigned char pixle) {
	Pixel **pixles_arr;
	//allocate the rows in the arr
	*pixles_arr = new(std::nothrow) Pixel[H];
	//check if its not NULL
	if (*pixles_arr == NULL) {
		std::cout << "error";
		exit(EXIT_FAILURE);
	}
	//allocate the cols of the arr and set the color
	for (int row = 0; row < H; row++) {
		pixles_arr[row] = new(std::nothrow) Pixel[W];
		//check if its not NULL
		if (pixles_arr[row] == NULL) {
			std::cout << "error";
			exit(EXIT_FAILURE);
		}
		//we set the color for every elment in the row
		for (int col = 0; col < W; col++) {
			pixles_arr[row][col].set_color(pixle);
		}
	}
}

//--------------------------------------------------
unsigned int ImageDataStructure::operator()(int row, int col) const {
	return m_arr[row][col].get_color();
}

//--------------------------------------------------
unsigned int ImageDataStructure::operator()(int row, int col){
	return m_arr[row][col].get_color();
}

//--------------------------------------------------
void ImageDataStructure::free(int rows) {
	for (int row = 0; row < rows; row++) {
		delete m_arr[row];
	}
	delete m_arr;
}

