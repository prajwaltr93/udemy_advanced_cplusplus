#include<iostream>
#include<map>

// maps with custom objects as value 
using namespace std;

class test {
    string name;
    int age;

    public:
    test() = default;

    test(string name, int age) : name(name), age(age) {
        // constructor initializer list
    }
};

int main() {

    map<int,test> abc;
    abc[0] = test("hello", 0);
    abc[1] = test("hello", 0);
    abc[2] = test("hello", 0);
    // abc[3]("hello", 0);

    return 0;
}