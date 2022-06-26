#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<int> a(1, 0);
    
    auto it = a.begin();

    cout << "capacity " << a.capacity() << endl;
    auto capactiy = a.capacity();
    
    for(auto i=0; i<capactiy + 10; i++) {
        cout << "increasing vector length" << endl;
        a.push_back(i);
    }

    cout << "pushed back" << endl;

    cout << *it <<endl;
    return 0;
}