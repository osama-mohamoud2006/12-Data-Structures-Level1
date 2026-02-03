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

void InsertAtTheEnd(Node *&Head, int value)
{
    // 1.Create New Node
    Node *NNode = new Node();
    NNode->SetValue(value);

    // P1: صحرا
    if (Head == nullptr)
    {
        Head = NNode; // as no node connected to head
        return ;
    };

    
    //P2 : there are nodes

    //1.traversing All Untill Get (The next address = null )
    Node * Temp = Head; 
    while(Temp!=nullptr)
    {
        Temp = Temp->GetTheAddressOfNextNode(); // go to the next node
    };

    //2.Here You Reached The (Next Address = null)
    Temp->SetTheAddressForTheNextNode(NNode); // Set The Next
    NNode->SetTheAddressForTheNextNode(nullptr);

}

