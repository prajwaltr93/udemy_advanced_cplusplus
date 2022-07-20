#include<iostream>
#include "bitmap.h"

using namespace std;

int _HEIGHT = 800;
int _WIDTH = 600;

int main() {

    bitmap bm_obj(_WIDTH, _HEIGHT);
    for(int i=0; i<_WIDTH; i++) {
        for(int j=0; j<_HEIGHT; j++) {
            bm_obj.set_pixel(i, j, 255, 0, 0);
        }
    }
    if(bm_obj.write_to_file("bitmap.bmp")) {
        cout << "file written" << endl;
    }
    else {
        cout << "Failed to Write to file" << endl;
    }
    return 0;
}