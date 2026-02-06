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

    NNode->Next = nullptr;

    if (Head == nullptr) // the first node
    {
        NNode->Prev = nullptr;
        Head = NNode;
        return;
    }

    else
    {
        Node *Current = Head;
        while (Current->Next != nullptr)
        {
            Current = Current->Next; // move to the next node
        };

        // the last node
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