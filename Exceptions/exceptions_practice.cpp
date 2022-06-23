// exception handling in c++
# include <exception>
# include <iostream> 

using namespace std;

class customException;
// custom exception class
class customException : public exception { // inheritance type private implied
private:
    const char * message = "Custom exception message";
public:
    virtual const char * what() {
        return message;
    }

};

// generic exception class bad_alloc, exception
void function_generic_exception() {
    throw customException();
}

// main 
int main() {
    try{
        function_generic_exception();
    }
    // catch (customException &e) {
    //     cout << e.what() <<endl;
    // }
    catch (exception e) { // private inheritance dis allows derived to base class conversion
        cout << "Base handling derived exception" << endl;
        cout << e.what() <<endl;
    }
}