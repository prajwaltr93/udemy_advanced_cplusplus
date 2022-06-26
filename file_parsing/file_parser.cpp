#include<iostream>
#include<fstream>

using namespace std;

int main() {

    fstream fh;
    string filename = "data.txt";
    string buffer = "";

    fh.open(filename, ios::in);

    if(fh.is_open()) {
        while(getline(fh, buffer, ':')) {
                cout << buffer <<endl;
                // skip space
                // fh.get();
                // getline(fh, buffer);
                // if(buffer.size()) {
                //     cout << buffer << endl;
                // }
        }
        fh.close();
    }
    else {
        cout << "Cannot Open File : " << filename <<endl;
    }
    return 0;
}