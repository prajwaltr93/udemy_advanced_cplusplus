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

    return 0;
}