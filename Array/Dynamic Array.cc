#include <iostream>
using namespace std;

template <class T> // template class
class clsDynamicArray
{
private:
    T *_APtr; // pointer to access heap to make dynamic array
    int _Length;
    int _Indx = 0; // to move in array indices

    void _ResizeTheArray() // make copy of array then insert the elements again with new length
    {

        T *TempArr = new T[_Length]; // TempArr (Dynamic array) with new length

        for (int i = 0; i < _Length; i++) // make a copy of the current array
        {
            TempArr[i] = _APtr[i];
        }

        _APtr = nullptr;
        delete[] _APtr; // delete the OG array

        int OldLen = _Length;
        _Length = _Length * 2;  // increment the length of array
        _APtr = new T[_Length]; // make  array with new length

        for (int i = 0; i < OldLen; i++) // make a copy of the current array
        {
            _APtr[i] = TempArr[i];
        }

        delete[] TempArr; // deallcote the TempArray
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
        if (_Indx > _Length)
        { // if the index exceed the length of array
            _ResizeTheArray();
        }

        *(_APtr + _Indx) = Element; // index zero  (using dereferencing)
        _Indx++;                    // increment the index
    }

    // Access
    T At(int Index) // return the element on specific index
    {
        if (Index > _Length)
            return -100;
        return _APtr[Index];
    }

    // Print
    void PrintAllElements()
    {
        for (int i = 0; i < this->_Indx; i++)
        { // print the filled indices only
            cout << *(_APtr + i) << " ";
        }
        cout << endl;
    }

    // Search
    bool IsElementExisting(T ElementToCheck)
    {
        for (int i = 0; i < this->_Indx; i++)
        {                                       //  the filled indices only
            if (*(_APtr + i) == ElementToCheck) // if the current element is the desired element
                return true;
        }
        return false; // if it wasn't existing
    }

    // Delete
    void PopBack() // O(1) Algorithm instead of O(N)
    {
        T *TempArr = new T[this->_Indx--]; // Temp dynamic array -- i used the index not the length to print the actual located size

        TempArr = clsDynamicArray<T>::_APtr; // copy the current array
        _APtr = TempArr;                     // fill the array again without the last element
        delete[] TempArr;                    // deallcoate the memory
    }

    // Update
    void UpdateElement(int IndexOfElement, T NewValue)
    {
        if (IndexOfElement > _Length)
            return;
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