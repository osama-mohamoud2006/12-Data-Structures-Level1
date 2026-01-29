#include <iostream>
#include <vector>
using namespace std;

template <class T> // template class
class clsDynamicArray
{
private:
    T *_APtr; // pointer to access heap to make dynamic array
    int _Length;
    int _Capacity = 0; // to move in array indices

    void _ResizeTheArray() // make copy of array then insert the elements again with new length
    {
        _Length = _Length * 2;       // increment the length of array
        T *ResizedArr = new T[_Length]; // ResizedArr (Dynamic array) with new length

        for (int i = 0; i < this->_Capacity; i++) // make a copy of the current array
        {
            ResizedArr[i] = _APtr[i];
        }

        delete[] _APtr; // delete the OG array
        _APtr = nullptr;
        _APtr = ResizedArr; // points to the new array 

    }

public:
    clsDynamicArray(int Length) // constructor
    {
        this->_Length = Length;
        _APtr = new T[Length]; // Dynamic array
    }

    // Fill , Insert
    void PushElement(T Element)
    {
        if (_Capacity > _Length) // _Capacity -->> index
        {                        // if the index exceed the length of array
            _ResizeTheArray();
        }

        *(_APtr + _Capacity) = Element; // index zero  (using dereferencing)
        _Capacity++;                    // increment the index
    }

    // Access
    T At(int Index) // return the element on specific index
    {
        if (Index > _Length || 0 > Index)
            throw out_of_range("Index out of range");

        return _APtr[Index];
    }

    // Print
    void PrintAllElements()
    {
        for (int i = 0; i < this->_Capacity; i++)
        { // print the filled indices only
            cout << *(_APtr + i) << " ";
        }
        cout << endl;
    }

    // Search
    bool IsElementExisting(T ElementToCheck)
    {
        for (int i = 0; i < this->_Capacity; i++)
        {                                       //  the filled indices only
            if (*(_APtr + i) == ElementToCheck) // if the current element is the desired element
                return true;
        }
        return false; // if it wasn't existing
    }

    // Delete
    void PopBack() // O(1) Algorithm instead of O(N)
    {
        T *ResizedArr = new T[this->_Capacity--]; // Temp dynamic array -- i used the index not the length to print the actual located size

        for (int i = 0; i < _Capacity; i++) // make a copy of the current array
        {
            ResizedArr[i] = _APtr[i];
        }

       delete [] _APtr;
       _APtr = nullptr;

       _APtr = ResizedArr; // pointer will point the new array 
    }

    // Update
    void UpdateElement(int IndexOfElement, T NewValue)
    {
        if (IndexOfElement > _Length || IndexOfElement < 0)
            throw out_of_range("Index out of range");

        _APtr[IndexOfElement] = NewValue;
    }

    ~clsDynamicArray() // destructor
    {
        delete[] _APtr; // deallocate the memory
    }
};

int main()
{
    clsDynamicArray<int> Arr1(5);
    Arr1.PushElement(1);
    Arr1.PushElement(2);
    Arr1.PushElement(3);
    Arr1.PushElement(4);
    Arr1.PushElement(5);
    Arr1.PushElement(6);
    Arr1.PushElement(7);
    Arr1.PushElement(8);
    Arr1.PushElement(9);
    Arr1.PushElement(10);

    Arr1.UpdateElement(0, -1);

    cout << "\nBefore Poping The Last Element \n";
    Arr1.PrintAllElements();

    Arr1.PopBack();
    cout << "\nAfter Poping The Last Element \n";
    Arr1.PrintAllElements();
}