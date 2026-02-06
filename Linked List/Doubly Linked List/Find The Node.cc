#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *Prev;
    Node *Next;

    Node(int value)
    {
        this->value = value;
        Prev = nullptr;
        Next = nullptr;
    };
};

void InsertAtTheBeginning(Node *&Head, int value)
{
    // create new node
    Node *NNode = new Node(value);

    // connect its prev with null as it will be the first node
    NNode->Prev = nullptr;

    // connect its Next Ptr with the first node (the current Head)
    NNode->Next = Head;

    if (Head != nullptr) // if the new node isn't the first node then we will connect the current head with new node as the prev node as the first node becomes the second node now
    {
        Head->Prev = NNode;
    }

    // Now Move The Head to the new Node Anyway
    Head = NNode;
};

void PrintNodeDetails(Node *&Head)
{
    // Format : Prev Value <--> The Current Node Value <--> The Next Node Value
    if (Head->Prev != nullptr) // prev
    {
        cout << Head->Prev->value;
    }
    else
    {
        cout << "NULL";
    }

    // current
    cout << " <--> " << Head->value << " <--> ";

    if (Head->Next != nullptr) // next
    {
        cout << Head->Next->value << "\n";
    }
    else
    {
        cout << "NULL\n";
    }
};

void PrintNodeByNodeDetails(Node *Head)
{

    while (Head != nullptr)
    {
        PrintNodeDetails(Head);
        Head = Head->Next; // move to the next node
    };
};

Node *FindNode(Node *Head, int value)
{
    while (Head != nullptr)
    {
        if (Head->value == value)
            return Head;   // if the current node is the desired node
        Head = Head->Next; // move to the next node
    };
    return nullptr;
};

int main()
{
    Node *Head = nullptr;
    InsertAtTheBeginning(Head, 40);
    InsertAtTheBeginning(Head, 30);
    InsertAtTheBeginning(Head, 20);
    InsertAtTheBeginning(Head, 10);

    Node *NodeToGet = FindNode(Head, 40);
    PrintNodeDetails(NodeToGet);


}