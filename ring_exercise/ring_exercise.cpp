#include<iostream>
#include<vector>
#include "ring.h"

using namespace std;

int main() {

    ring<int> store(3);
    store.add(1);
    store.add(2);
    store.add(3);
    store.add(4);
    store.add(5);

    for(int i=0; i<store.get_size(); i++) {
        cout<< store.get(i) << endl;
    }
    for(ring<int>::iterator it = store.begin(); it != store.end(); it++) {
        cout<< *it << endl;
    }
    for(auto x : store) {
        cout<< x << endl;
    }

    return 0;
}