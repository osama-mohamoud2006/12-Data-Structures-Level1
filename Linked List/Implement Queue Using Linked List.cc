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

template <class T>
class QueueInterface // Abstract Class - Contract 
{
    virtual void push() = 0;
    virtual void pop() = 0;
    virtual T front() = 0;
    virtual T back() = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
};

template <class T>
class queue : private QueueInterface<T>
{
private:
    Node *Head;

public:
    queue()
    {
        Head = nullptr;
    }


};