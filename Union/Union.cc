#include <iostream>
#include <string>
using namespace std;

union MyUnion
{
    int IntValue;
    float FValue;
    char Char;
};

int main()
{
    MyUnion U1;
    U1.IntValue = 100;
    U1.FValue = 90.1f;
    U1.Char = 'x';

    cout << U1.IntValue << endl; // will print garage value as it isn't the last written element
                                 // you should access the last one at first

    
    // assigning value to element (which isn't the last) and then accessing another leads to undefined behaviour
    U1.IntValue = 100;
    cout << "\n"
         << U1.FValue << endl;
}