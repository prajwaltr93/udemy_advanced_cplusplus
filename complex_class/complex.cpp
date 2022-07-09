#include<iostream>

using namespace std;

class complex {
    int real, imaginary;

    public:
        complex() : real(0), imaginary(0) {

        }
        complex(int a, int b) : real(a), imaginary(b) {

        }
        complex(complex &oth) {
            // cout << "Copy Constructor Called" << endl;
            real = oth.real;
            imaginary = oth.imaginary;
        }
    
        complex& operator=(const complex &oth){
            // cout << "Assignment operator overloaded" << endl;

            real = oth.real;
            imaginary = oth.imaginary;
            return *this;
        }

    friend ostream& operator<<(ostream &out, const complex &other);

};

ostream& operator<<(ostream &out, const complex &other) {
    out << other.real << " + " << other.imaginary;
    return out;
}

int main() {

    complex a;
    complex b(1, 2);
    cout << a << endl;
    a = b;
    cout << a << endl;
    complex c(b);

    cout << c << endl;

    cout<< "Compiled" << endl;
    return 0;
}