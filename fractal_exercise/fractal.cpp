#include<iostream>
#include "bitmap.h"
#include "mandelbrot.h"
#include <math.h>
#include "zoomlist.h"
#include "RGB.h"

using namespace std;


int main() {

    int const WIDTH = 800;
	int const HEIGHT = 600;

	bitmap bitmap_obj(WIDTH, HEIGHT);

	RGB startColor(0, 0, 20);
	RGB endColor(255, 128, 74);
	RGB colorDiff = endColor - startColor;

	int *histogram = new int[Mandelbrot::MAX_ITERATIONS]{0}; // all index set to 0, count = 0
	int *fractal = new int[WIDTH * HEIGHT]{0}; // all index set to 0, count = 0

	ZoomList zoomList(WIDTH, HEIGHT);

	zoomList.add(Zoom(WIDTH / 2, HEIGHT / 2, 4.0 / WIDTH));
	// zoomList.add(Zoom(295, HEIGHT - 202, 0.1));
	// zoomList.add(Zoom(312, HEIGHT - 304, 0.1));

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			pair<double, double> coords = zoomList.doZoom(x, y); 

			int iterations = Mandelbrot::getIterations(coords.first, coords.second);

			fractal[y*WIDTH + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				*(histogram + iterations) += 1;
			}
		}
	}
   
	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		total += histogram[i];
	}

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {

			uint8_t red=0;
			uint8_t green=0;
			uint8_t blue=0;

			int iterations = fractal[y * WIDTH + x];

			double hue = 0.0;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				for (int i = 0; i <= iterations; i++) {
					hue += ((double) histogram[i]) / total;
					
					red = startColor.r + colorDiff.r*hue;
					green = startColor.g + colorDiff.g*hue;
					blue = startColor.b + colorDiff.b*hue;

					bitmap_obj.set_pixel(x, y, red, green, blue);
				}
			}
			bitmap_obj.set_pixel(x, y, red, green, blue);
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