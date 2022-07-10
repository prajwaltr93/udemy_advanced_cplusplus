#include <iostream>

using namespace std;

template<class t>
void func(t value) {
    if (typeid(value).name() == typeid(string).name()) {
        cout << "found string" << endl;
    }
    else {
        cout << "found int" << endl;
    }
}
int main() {
    string a = "hellow";
    int b = 10;

    func(a);
    func(b);

    return 0;

}