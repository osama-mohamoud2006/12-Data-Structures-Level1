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

void DeleteTheFirstNode(Node *&Head)
{
    // if the linked list is empty
    if (Head == nullptr)
        return;

    Node *CurrentNode = Head;
    
    Head = Head->GetTheAddressOfNextNode(); // move the Head to next node
    CurrentNode->SetTheAddressForTheNextNode(nullptr);
    delete CurrentNode;
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
    Node *Node1 = new Node();
    Node *Node2 = new Node();
    Node *Node3 = new Node();
    Node *Node4 = new Node();

    Node1->SetValue(10);
    Node2->SetValue(20);
    Node3->SetValue(30);
    Node4->SetValue(40);

    Node1->SetTheAddressForTheNextNode(Node2);
    Node2->SetTheAddressForTheNextNode(Node3);
    Node3->SetTheAddressForTheNextNode(Node4);
    Node4->SetTheAddressForTheNextNode(nullptr);

    Head = Node1;

    cout << "\nBefore Deleting The First Node\n";
    PrintList(Head);

    cout << "\nAfter Deleting The First Node\n";
    DeleteTheFirstNode(Head);
    PrintList(Head);
};