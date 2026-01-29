#include <iostream>
using namespace std;

template <class T> // template class
class clsDynamicArray
{
private:
    T *_APtr; // pointer to access heap to make dynamic array
    int _Length;
    int _Indx = 0; // to move in array indices

public:
    clsDynamicArray(int Length) // constructor
    {
        this->_Length = Length;
        _APtr = new T[Length]; // Dynamic array
    }

    // Fill , Insert
    void PushElement(T Element)
    {
        *(_APtr + _Indx) = Element; // index zero  (using dereferencing)
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
    void PopBack() //O(1) Algorithm instead of O(N)
    {
        T *TempArr = new T[this->_Indx--]; // Temp dynamic array
        TempArr = clsDynamicArray<T>::_APtr;   // copy the current array
        _APtr = TempArr;                       // fill the array again without the last element
    }

    // Update
    void UpdateElement(int IndexOfElement, T NewValue)
    {

        _APtr[IndexOfElement] = NewValue;
    }
};

int main()
{
    clsDynamicArray<int> Arr1(5);
    Arr1.PushElement(1);
    Arr1.PushElement(2);
    Arr1.PushElement(3);

    cout << "\nBefore Poping The Last Element \n";
    Arr1.PrintAllElements();

    Arr1.PopBack();
    cout << "\nAfter Poping The Last Element \n";
    Arr1.PrintAllElements();
}