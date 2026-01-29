#include <iostream>
using namespace std;

int sum(int *ptr1, int *ptr2)
{
    return *ptr1 + *ptr2; // deref
}

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

struct stData
{
    short Age = 0;
    string Name = "";
};

class clsTest
{
public:
    int x = 10;
    int z = 100;
};

int main()
{

    int x = 10;
    int *Ptr = &x; // should be the same data type

    cout << &Ptr << endl;
    cout << &x << endl;

    int y = 200;
    Ptr = &y; // now it has the ref of y

    cout << &Ptr << endl; // ptint the address of pointer
    cout << &y << endl;   // print the addrees of y
    cout << Ptr << endl;  // print the addrees of y

    int z = 100;
    int *Ptr2 = &z;
    cout << *Ptr2 << endl; // dereferceing the pointer--> will print the val of Z

    *Ptr2 = 200; // you can change the value by the pointer
    cout << z << endl;

    // *Ptr2 = & x; // deref can store vals not addresses
    int n1, n2;
    n1 = 10, n2 = 20;
    cout << sum(&n1, &n2) << endl;

    cout << n1 << "  " << n2 << endl;
    swap(&n1, &n2);
    cout << n1 << "  " << n2 << endl;

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    cout << arr << endl;  // will print the address of array
    cout << *arr << endl; // will print the first index val

    int *APtr = arr;
    cout << APtr << endl;
    cout << *APtr << endl;

    cout << APtr + 1 << endl;
    cout << APtr + 2 << endl;

    cout << *APtr + 1 << endl;
    cout << *APtr + 2 << endl;

    for (int i = 0; i < 7; i++)
        cout << *(arr + i) << " ";

    for (int i = 0; i < 7; i++)
        cout << *APtr + i << " ";
    cout << endl;

    char AOfC[] = {'a', 'b', 'c'};
    char *ptr = AOfC;
    cout << *(ptr + 1) << endl; // first index 'a'
    cout << ptr << endl;        // will print the entire array

    stData data; // def the struct
    stData *StPtr = &data;

    StPtr->Age = 10;
    StPtr->Name = "ola";
    data = *StPtr;
    cout << data.Name << endl;
    cout << data.Age << endl;

    int v = 202;
    void *VPtr = &v;
    cout << VPtr << endl; // the address of pointer
    // cout<< * VPtr <<endl; // you cann't deref it as it is void

    cout << *(static_cast<int *>(VPtr)) << endl; // YOU SHOULD CONVERT THE VOID TO dt

    int *H1 = new int; // stores int in heap
    *H1 = 2902;
    cout << *H1 << endl;
    delete H1; // deallocate the H1 from heap memory

    cout << "\nArray \n";
    const int l = 3;
    int arr2[l];
    arr2[0] = 1;
    arr2[1] = 2;
    arr2[2] = 3;
    arr2[3] = 4;
    for (int i = 0; i < 3; i++)
        cout << *(arr2 + i) << endl;

    int len = 4;

    int *Harr = new int[len]; // allocate array in heap memory (dynamic array)

    *Harr = 0;       // index 0
    *(Harr + 1) = 1; // index 1
    *(Harr + 2) = 2; // index 2
    *(Harr + 3) = 3; // index 3
    *(Harr + 4) = 4; // index 4
    *(Harr + 5) = 5; // index 5
    *(Harr + 6) = 6; // index 6

    cout << *(Harr + 4) << endl; // print the index 4

    for (int i = 0; i <= 6; i++)
    {
        cout << *(Harr + i) << endl;
    }

    delete[] Harr;
    Harr = nullptr;

    clsTest *clsPtr = new clsTest(); // allocate dynamic obj 
    cout<< clsPtr->x <<endl; 
}