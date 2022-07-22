#include "RGB.h"

RGB::RGB(double r, double g, double b): r(r), g(g), b(b) {
	// TODO Auto-generated constructor stub

}

RGB RGB::operator-(const RGB& second) {
	return RGB(r - second.r, g - second.g, b - second.b);
}

ostream& operator<<(ostream& out, const RGB& rgb) {
    out << rgb.r  << rgb.r << rgb.r;

    return out;
}