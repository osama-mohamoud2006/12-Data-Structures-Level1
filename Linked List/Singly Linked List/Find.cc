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

void InsertAtTheBegging(Node *&Head, int value)
{
    Node *NNode = new Node(); // create new node
    NNode->SetValue(value);
    NNode->SetTheAddressForTheNextNode(Head); // take the address of first node from the head
    Head = NNode;                             // move the head to the new node
}

void PrintList(Node *Head)
{
    while (Head != nullptr)
    {
        cout << Head->GetValue() << endl;
        Head = Head->GetTheAddressOfNextNode();
    }
}

Node *Search(Node *Head, int value)
{
    while (Head != nullptr)
    {
        if (Head->GetValue() == value)
            return Head;
        Head = Head->GetTheAddressOfNextNode();
    }
    return nullptr;
}

int main()
{
    Node *Head = nullptr;
    InsertAtTheBegging(Head, 10);
    InsertAtTheBegging(Head, 20);
    InsertAtTheBegging(Head, 30);
    InsertAtTheBegging(Head, 40);
    InsertAtTheBegging(Head, 50);

    PrintList(Head);

    if (Search(Head, 50) != nullptr)
        cout << "Found The Node!\n";
    else
        cout << "NULL !\n";
}