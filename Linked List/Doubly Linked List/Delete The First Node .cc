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

void DeleteTheFirstNode(Node *&Head)
{
    if (Head == nullptr) // if no head then no nodes
        return;

    if (Head->Next != nullptr) // if there is other nodes then make the prev of the next node to null as it will be the first node
    {
        Head->Next->Prev = nullptr;
    };

    Node *Temp = Head; // make pointer to the current node 'Head'
    Head = Head->Next; // move the head to the next node 
    delete Temp; // delete the the first node 'The Head Perviously' 
};

void InsertAtTheBeginning(Node *&Head, int value)
{

    Node *NNode = new Node(value);

    if (Head == nullptr)
    {
        Head = NNode;
        return;
    };

    Head->Prev = NNode;
    NNode->Next = Head;

    Head = NNode;
    NNode->Prev = nullptr;
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

int main()
{
    Node *Head = nullptr;
    InsertAtTheBeginning(Head, 90);
    InsertAtTheBeginning(Head, 80);
    InsertAtTheBeginning(Head, 70);
    InsertAtTheBeginning(Head, 60);

    cout << "\nBefore Deleting The First Node\n";
    PrintNextNode(Head);

    DeleteTheFirstNode(Head);

    
    cout << "\nAfter Deleting The First Node\n";
    PrintNextNode(Head);

}