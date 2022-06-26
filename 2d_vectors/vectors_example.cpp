#include<iostream>
#include<vector>

using namespace std;

int main() {
    // 2d vector repr 12 table

    vector<vector<int>> table12(10, vector<int>(2, 0));

    for(int i=0; i<table12.size(); i++) {
        table12[i][0] = i + 1;

        table12[i][1] = (i + 1) * 12;
    }

    for(int i=0; i<table12.size(); i++) {
        cout << 12 << " * " << table12[i][0] << " = " << table12[i][1] << endl;
    }

    return 0;
}