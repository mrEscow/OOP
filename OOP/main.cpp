#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;


int main()
{
    int* a = nullptr;

    cout << a << endl;

    if (a) {
        cout << "not nullptr" << endl;
    }
    else {
        cout << "nullptr" << endl;
    }

    if (a == nullptr) {
        cout << "nullptr" << endl;
    }
    else{
        cout << "not nullptr" << endl;
    }
    return 0;
}



