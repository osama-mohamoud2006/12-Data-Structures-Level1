#include <iostream>
using namespace std;

template <class T> // template class
class clsDynamicArray
{
private:
    T *_APtr; // pointer to access heap to make dynamic array
    int _Length;
    int _Indx = 0; // to move in array indeces

public:
    clsDynamicArray(int Length) // constructor
    {
        this->_Length = Length;
        _APtr = new T[Length]; // Dynamic array
    }

    // Fill
    void PushElement(T Element)
    {
        *(_APtr + _Indx) = Element; // index zero  (using derefrencing)
        _Indx++;                    // increment the index
    }

    // Access
    T AccessSpecificElement(int Index)
    {
        return _APtr[Index]; // return the element on specific index
    }

    // Print
    void PrintAllElements()
    {
        for (int i = 0; i < this->_Indx; i++)
        { // print the filled indeces only
            cout << *(_APtr + i) << " ";
        }
        cout << endl;
    }

    // Search
    bool IsElementExisting(T ElementToCheck)
    {
        for (int i = 0; i < this->_Indx; i++)
        {                                       //  the filled indeces only
            if (*(_APtr + i) == ElementToCheck) // if the current element is the desired element
                return true;
        }
        return false; // if it wasn't existing
    }
    // Insert
    // Delete
    // Update
};

int main()
{
    clsDynamicArray<int> Arr1(5);
    Arr1.PushElement(1);
    Arr1.PushElement(2);
    Arr1.PushElement(3);
    Arr1.PrintAllElements();

    cout << Arr1.IsElementExisting(1) << endl;
}