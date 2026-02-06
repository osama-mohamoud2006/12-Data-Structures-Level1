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

void DeleteTheNode(Node *&TheNodeYouWantToDelete, Node *&Head)
{
    if (Head == nullptr || TheNodeYouWantToDelete == nullptr) 
        return;

    if (TheNodeYouWantToDelete == Head) // move the head to the next node if you want to delete the first node 
    {
        Head = TheNodeYouWantToDelete->Next;
    }

    if (TheNodeYouWantToDelete->Next != nullptr) // There is next node
    {
        TheNodeYouWantToDelete->Next->Prev = TheNodeYouWantToDelete->Prev; //set the prev of next node to the prev of the current node 
    };

    if (TheNodeYouWantToDelete->Prev != nullptr) // there is prev node
    {
        TheNodeYouWantToDelete->Prev->Next = TheNodeYouWantToDelete->Next; // set the next of prev node to the next of current node 
    };

    delete TheNodeYouWantToDelete; // delete the current node 
    TheNodeYouWantToDelete=nullptr;
};

void InsertAtTheEnd(Node *&Head, int value)
{

    Node *NNode = new Node(value);
    NNode->Next = nullptr;

    if (Head == nullptr)
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
            Current = Current->Next;
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
int main()
{
    Node *Head = nullptr;
    InsertAtTheEnd(Head, 10);
     InsertAtTheEnd(Head, 20);
     InsertAtTheEnd(Head, 30);
     InsertAtTheEnd(Head, 40);

    cout << "\nBefore Deleting\n";
    PrintNextNode(Head);

    Node *TheNodeToDelete = Find(Head, 10);
    DeleteTheNode(TheNodeToDelete, Head);

    cout << "\nAfter Deleting\n";
    PrintNextNode(Head);
}