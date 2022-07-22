#include<iostream>
#include "bitmap.h"
#include "mandelbrot.h"

using namespace std;


int main() {

    int const WIDTH = 800;
	int const HEIGHT = 600;

	bitmap bitmap_obj(WIDTH, HEIGHT);

	double min = 999999;
	double max = -999999;

	int *histogram = new int[Mandelbrot::MAX_ITERATIONS]{0}; // all index set to 0, count = 0
	int *fractal = new int[WIDTH * HEIGHT]{0}; // all index set to 0, count = 0

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			double xFractal = (x - WIDTH/2 - 200) * 2.0/HEIGHT;
			double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);

			fractal[y*WIDTH + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				*(histogram + iterations) += 1;
			}

			uint8_t color = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);

            color = color * color * color;

			bitmap_obj.set_pixel(x, y, 0, color, 0);
			if(color < min) min = color;
			if(color > max) max = color;
		}
	}
   
	// for(int x=0; x < Mandelbrot::MAX_ITERATIONS; x++) {
	// 	if (*(histogram + x) !=0 ){
	// 		cout << x << " : " << *(histogram + x) << endl;
	// 	}
	// }
	
	// free the array 
	delete[] histogram;
	delete[] fractal;

    if(bitmap_obj.write_to_file("bitmap.bmp")) {
        cout << "file written" << endl;
    }
    else {
        cout << "Failed to Write to file" << endl;
    }
    return 0;
}