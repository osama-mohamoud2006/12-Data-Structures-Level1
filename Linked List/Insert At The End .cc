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
        return;
    };

    // P2 : there are nodes

    // 1.traversing All until Get (The next address = null )
    Node *Temp = Head;
    while (Temp != nullptr)
    {
        Temp = Temp->GetTheAddressOfNextNode(); // go to the next node
    };

    // 2.Here You Reached The (Next Address = null)
    Temp->SetTheAddressForTheNextNode(NNode);    // Set The Next Address Of The Last Node(Perviously) To New Node
    NNode->SetTheAddressForTheNextNode(nullptr); // This The Last Node
};

int main()
{
    Node *Head = nullptr;
    InsertAtTheEnd(Head, 10);
    InsertAtTheEnd(Head, 20);
    InsertAtTheEnd(Head, 30);
    InsertAtTheEnd(Head, 40);

    while (Head != nullptr)
    {
        cout << Head->GetValue() << endl;
        Head = Head->GetTheAddressOfNextNode();
    }
}
