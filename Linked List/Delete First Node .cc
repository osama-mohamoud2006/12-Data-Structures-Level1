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
    if (Head->GetTheAddressOfNextNode() == nullptr) // if there is one node only
    {
        delete CurrentNode;
        Head = nullptr;
        return;
    }

    else // if there are other nodes
    {
        Head = Head->GetTheAddressOfNextNode(); // move the Head to next node
        CurrentNode->SetTheAddressForTheNextNode(nullptr);
        delete CurrentNode;
    };
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

    Head = Node1;
    Node1->SetValue(10);
    Node2->SetValue(20);
    Node3->SetValue(30);
    Node4->SetValue(40);
    cout << "\nBefore Deleting The First Node\n";
    PrintList(Head);
};