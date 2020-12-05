#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#include "Image.h"

int main() {
	cout << "Pixel tests:\n";
	Pixel array[6] = { BLACK, BLACK, BLACK, BLACK, GRAY, WHITE };

	cout << array[0] << array[1] << array[2]
		<< array[3] << array[4] << array[5] << endl;

	array[0] = array[5];

	cout << array[0] << array[1] << array[2]
		<< array[3] << array[4] << array[5] << endl;

	array[1] &= array[4];
	array[0] |= array[4];

	cout << array[0] << array[1] << array[2]
		<< array[3] << array[4] << array[5] << endl;

	if (!(array[0] != array[5])) {
		cout << array[0] << array[1] << array[2]
			<< array[3] << array[4] << array[0] << endl;
	}
	else {
		cout << array[0] << array[1] << array[2]
			<< array[3] << array[4] << array[5] << endl;
	}

	cout << (Pixel)BLACK << endl;

	cout << "\n--------------------------------------\n"
		<< "Image tests:\n";

	Image image1(5, 10, WHITE);

	Image image2(10, 20, GRAY);

	Image image3(20, 15, BLACK);

	image2 |= image1;
	image2 *= 3;
	image1 += image2;
	image3 &= image1;
	image3 *= 2;
	cout << image1 << image2 << image3;

	cout << image1 << endl << image2 << endl << image3 << endl;

	image1 += image2;
	image1 += image3;

	cout << image1 << endl << image2 << endl << image3 << endl;

	cout << image1 << endl << ~image1 << endl;

	image2 |= image3;

	cout << image2 << endl;

	image2 += image1;

	cout << image2 << endl;

	image2 &= image1;

	cout << image2 << endl;
	
	return EXIT_SUCCESS;
}