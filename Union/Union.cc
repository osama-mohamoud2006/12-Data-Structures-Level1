#include <iostream>
#include <string>
using namespace std;

union MyUnion
{
    int IntValue;
    float FValue;
    char Char;
};

struct Stdata
{
    int IntValue;
    float FValue;
    char Char;
};
int main()
{
    MyUnion U1;
    // Union values have the same memory address
    U1.IntValue = 100;
    cout << "Int Val: " << U1.IntValue << endl;
    cout << "Address: " << &U1.IntValue << endl;

    U1.FValue = 90.1f;
    cout << "Float Val: " << U1.FValue << endl;
    cout << "Address: " << &U1.FValue << endl;

    U1.Char = 'x';
    cout << "Char Val: " << U1.Char << endl;
    cout << "Address: " << &U1.Char << endl;

    cout << U1.IntValue << endl; // will print garage value as it isn't the last written element
                                 // you should access the last one at first

    // assigning value to element (which isn't the last) and then accessing another leads to undefined behaviour
    U1.IntValue = 100;
    cout << "\n"
         << U1.FValue << endl;

    Stdata St1;
    St1.IntValue = 10;

    cout << &St1.IntValue << endl;
    St1.FValue = 20.2f;

    cout << &St1.FValue << endl;

    St1.Char = 'a';
    cout << &St1.Char << endl;
    
};