#include <iostream>
using namespace std;

class Node
{
private:
    Node *Ptr;
    int Value;

public:
    Node()
    {
        Ptr = nullptr;
        Value = 0;
    }
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

// insert at the begging
void InsertAtTheBegging(Node *&Head, int value)
{
    Node *NNode = new Node();
    NNode->SetValue(value);

    if (Head == nullptr) //  the inserted node is the first node
    {
        Head = NNode;
        return;
    };
    NNode->SetTheAddressForTheNextNode(Head);
    Head = NNode;
};

void DeleteTheLastNode(Node *&Head)
{
    if (Head == nullptr)
        return; // the linked list is empty

    if (Head->GetTheAddressOfNextNode() == nullptr) // there is one node only
    {
        delete Head;
        Head = nullptr;
        return;
    };
    Node *Prev = Head;
    Node *Current = Head;
    while (Current->GetTheAddressOfNextNode() != nullptr) // traversing until the last node
    {
        Prev = Current;
        Current = Current->GetTheAddressOfNextNode(); // move to the next node
    };

    Prev->SetTheAddressForTheNextNode(nullptr);
    delete Current;
};

Node *Find(Node *Head, int value)
{
    while (Head != nullptr)
    {
        if (Head->GetValue() == value)
            return Head;
        Head = Head->GetTheAddressOfNextNode();
    }
    return nullptr;
};

void PrintList(Node *Head)
{
    while (Head != nullptr)
    {
        cout << Head->GetValue() << endl;
        Head = Head->GetTheAddressOfNextNode(); // move to the next address
    };
};

int main()
{
    Node *Head = nullptr;
    InsertAtTheBegging(Head, 40);
    InsertAtTheBegging(Head, 30);
    InsertAtTheBegging(Head, 20);
    InsertAtTheBegging(Head, 10);

    cout << "\nBefore Deleting The Last Node\n";
    PrintList(Head);

   
    cout << "\nAfter Deleting The Last Node\n";
    DeleteTheLastNode(Head);
    PrintList(Head);
}