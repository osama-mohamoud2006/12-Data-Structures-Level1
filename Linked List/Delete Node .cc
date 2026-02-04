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

Node * Find(Node * Head , int value)
{
    while(Head!=nullptr)
    {
        if(Head->GetValue() == value) return Head;
        Head = Head->GetTheAddressOfNextNode();
    }
    return nullptr; 
};

