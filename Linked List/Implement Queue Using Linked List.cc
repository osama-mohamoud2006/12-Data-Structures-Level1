#include <iostream>
using namespace std;

class Node
{
private:
    Node *Ptr;
    int Value;

public:
    void SetTheAddressForTheNextNode(Node *Ptr)
    {
        this->Ptr = Ptr;
    }

    void SetValue(int Value)
    {
        this->Value = Value;
    }

    // Get
    int GetValue() { return Value; }
    Node *GetTheAddressOfNextNode() { return this->Ptr; }
};

class queue
{
private:
    Node *Head;

public:
    queue()
    {
        Head = nullptr;
    }

    /*
    push()
 pop()
 front()
 back()
 size()
 empty()
    */
};