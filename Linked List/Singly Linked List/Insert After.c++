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

Node *Find(Node *Head, int value)
{
    while (Head != nullptr)
    {
        if (Head->GetValue() == value) // if the current node have the desired value
            return Head;
        Head = Head->GetTheAddressOfNextNode(); // move to the next node
    }
    return nullptr; // if it failed to get the value
};

void InsertAfter(Node *TheNodeToInsertAfter, int value)
{
    if (TheNodeToInsertAfter != nullptr) // if the node exists
    {
        // 1.Create New Node
        Node *NNode = new Node();
        NNode->SetValue(value);

        // 2.Take The Next Address Of New Node From The 'TheNodeToInsertAfter'
        NNode->SetTheAddressForTheNextNode(TheNodeToInsertAfter->GetTheAddressOfNextNode());

        // 3. The 'TheNodeToInsertAfter' Next Node Will Be The New Node Address
        TheNodeToInsertAfter->SetTheAddressForTheNextNode(NNode);
    }
};

void PrintList(Node *Head)
{
    while (Head != nullptr)
    {
        cout << Head->GetValue() << endl;
        Head = Head->GetTheAddressOfNextNode();
    }
};

void InsertAtBegging(Node *&Head, int value)
{
    Node *NNode = new Node();
    NNode->SetValue(value);
    NNode->SetTheAddressForTheNextNode(Head);
    Head = NNode;
};

int main()
{
    Node *Head = nullptr;
    InsertAtBegging(Head, 900); // 3
    InsertAtBegging(Head, 800); // 2
    InsertAtBegging(Head, 700); // 1

    cout << "\nBefore Inserting\n";
    PrintList(Head);

    Node *Node2 = Find(Head, 800); // get the address of 'Node2' (if it exists)
    InsertAfter(Node2, 850);

    cout << "\nAfter Inserting\n";
    PrintList(Head);

};
