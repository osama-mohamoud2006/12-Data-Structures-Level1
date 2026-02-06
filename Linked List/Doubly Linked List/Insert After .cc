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

Node *Find(Node *Head, int value)
{
    while (Head != nullptr)
    {
        if (Head->value == value)
            return Head;
        Head = Head->Next;
    }
    return nullptr;
}

void InsetAtTheBeginning(Node *&Head, int value)
{
    // create new node
    Node *NNode = new Node(value);

    NNode->Next = Head;
    NNode->Prev = nullptr;

    if (Head != nullptr)
    {
        Head->Prev = NNode;
    }

    Head = NNode;
}

void InsertAfter(Node *&TheNodeToInsertAfter, int value)
{
    if (TheNodeToInsertAfter == nullptr)
        return;
    // 1. Create New Node
    Node *NNode = new Node(value);

    NNode->Next = TheNodeToInsertAfter->Next;
    NNode->Prev = TheNodeToInsertAfter;

    if (TheNodeToInsertAfter->Next != nullptr)
    {
        TheNodeToInsertAfter->Next->Prev = NNode;
    }

    TheNodeToInsertAfter->Next = NNode;
}

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
    InsetAtTheBeginning(Head, 40);
    InsetAtTheBeginning(Head, 30);
    InsetAtTheBeginning(Head, 20);
    InsetAtTheBeginning(Head, 10);

    cout<<"\nBefore Inserting After\n";
    PrintNextNode(Head);

    Node * Find
}