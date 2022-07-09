#include<iostream>
#include<vector>

using namespace std;

bool test(int value) {
    return value;
}

bool test(string s) {
    return s == "hellow";
}

template<class t>
int count_of(const vector<t> &store, bool (*match)(t)) {
    int tally = 0;
    for(auto x : store) {
        if(match(x)){
            tally++;
        }
    }
    return tally;
}

int main() {

    vector<int> store{0, 1, 2, 0, 4};
    vector<string> stores{"hellow", "world", "hellow"};
    cout << count_of(stores, test) << endl;
    return 0;
}