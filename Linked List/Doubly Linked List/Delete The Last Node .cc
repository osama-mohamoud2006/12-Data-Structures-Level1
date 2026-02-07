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

void DeleteTheLastNode(Node *&Head)
{
    if (Head == nullptr)
        return;

    if (Head->Next == nullptr) // if there is one node only 
    {
        delete Head;
        Head = nullptr;
        return;
    };

    Node *Temp = Head;
    while (Temp->Next->Next != nullptr) // find the Next ptr of the node that prev the last node 
    {
        Temp = Temp->Next;
    };

    // got the node prev the last node
    delete Temp->Next;
    Temp->Next = nullptr;
};

void InsertAtTheBeginning(Node *&Head, int value)
{
    Node *NNode = new Node(value);
    NNode->Prev = nullptr;

    if (Head == nullptr)
    {
        NNode->Next = nullptr;
        Head = NNode;

        return;
    }
    NNode->Next = Head;
    Head->Prev = NNode;
    Head = NNode;
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
    InsertAtTheBeginning(Head, 800);
    InsertAtTheBeginning(Head, 700);
    InsertAtTheBeginning(Head, 600);
    InsertAtTheBeginning(Head, 500);

    cout<<"\nBefore Deleting The LastNode\n";
    PrintNextNode(Head);

    DeleteTheLastNode(Head); 

        cout<<"\nAfter Deleting The LastNode\n";
    PrintNextNode(Head);
}