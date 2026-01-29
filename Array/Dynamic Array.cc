#include <iostream>
using namespace std;

template <class T> // template class 
class clsDynamicArray
{
private:
    T *_APtr; // pointer to access heap to make dynamic array
    int _Length;

public:
    clsDynamicArray(int Length) // constructor 
    {
        this->_Length = Length;
        _APtr = new T [Length]; // Dynamic array 
    }

    // Access

    // Search 
    // Insert
    //Delete
    // Update



};