#include <iostream>

using namespace std;

struct RGB {
	double r;
	double g;
	double b;

	RGB(double r, double g, double b);
    RGB operator-(const RGB& second);
    friend ostream& operator<<(ostream&, const RGB&);
};
