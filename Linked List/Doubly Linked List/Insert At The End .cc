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

void InsertAtTheEnd(Node *&Head, int value)
{
    // 1.create new node
    Node *NNode = new Node(value);

    NNode->Next = nullptr; // The Next Ptr Will Be Null As It Is The Last Node

    if (Head == nullptr) // If The New Node Is The First Node
    {
        NNode->Prev = nullptr;
        Head = NNode; //as it is the first node 
        return;
    }

    else
    {
        Node *Current = Head; // make copy of head to traversing all nodes 
        while (Current->Next != nullptr)
        {
            Current = Current->Next; // move to the next node
        };

        // Got the last node
        Current->Next = NNode; 
        NNode->Prev = Current;
    }
};

void PrintNextNode(Node *Head)
{
    cout << "NULL" << " <--> ";
    while (Head != nullptr)
    {
        cout << Head->value << " <--> ";
        Head = Head->Next;
    }
    cout << "NULL";
}

int main()
{
    Node *Head = nullptr;
    InsertAtTheEnd(Head, 10);
    InsertAtTheEnd(Head, 20);
    InsertAtTheEnd(Head, 30);
    InsertAtTheEnd(Head, 40);

    PrintNextNode(Head); 
}