#include <iostream>
#include <fstream>

using namespace std;

int main() {

    string filename = "test_file_operations.cpp";
    fstream streamobj;
    string buffer;

    cout<< "reading file" << endl;

    streamobj.open(filename, ios::in);

    if(streamobj.is_open()) {
        while(streamobj) {
            getline(streamobj, buffer);
            cout << buffer << endl;
        }
    }
    else {
        cout << "Failed to Read File : " << filename << endl;
    }
    streamobj.close();

    return 0;
}