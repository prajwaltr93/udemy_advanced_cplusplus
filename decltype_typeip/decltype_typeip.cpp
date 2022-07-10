#include<iostream>

using namespace std;

// decltype, nameid

int main() {
    string s = "helow";
    decltype(s) s2 = "hello there";
    // if(typeid(s) == typeid(string)) { // this works too :)
    if(typeid(s) == typeid(s2)) {
        cout << "they Match !!" << endl;
    }

    cout << "Compiled" << endl;

    return 0;
}