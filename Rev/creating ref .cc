#include <iostream>
#include <string>
using namespace std;

int main()
{

    int x = 20;
    int &Alies = x; // Alies , x will be the same address on memory so any change on one of them will affect the other

    cout << Alies << endl;
    cout << x << endl;

    Alies = 100; // ..  x = Alies  , x = Alies = 100
    cout << Alies << endl;
    cout << x << endl;

    x = 200;
    cout << Alies << endl;
    cout << x << endl;

    
}