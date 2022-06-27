#include<iostream>
#include<string>

using namespace std;

class test {
    private:
        string name;
        int id;
    public:
        test() = default;

        test(string name, int id) : name(name), id(id) {

        }
        // copy constructor
        test(test &other) {
            cout << "copy constructor called" << endl;
            this->id =  other.id + 1;
            this->name = other.name;
        }


        // assignment
        test& operator=(test &other) {
            this->id =  other.id + 1;
            this->name = other.name;
            return *this;
        }

        // utility function
        void print() {
            cout << name << " " << id << endl;
        }
};


int main() {

    test abc("name", 1);
    abc.print();

    test abcd;
    abcd = abc;

    abcd.print();
    
    test xyz = abcd;

    xyz.print();
    return 0;
}