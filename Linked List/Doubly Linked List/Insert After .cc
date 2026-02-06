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

    NNode->Next = TheNodeToInsertAfter->Next; // 2.Set The Next Ptr Of The New Node To The Next Node Of The Current Node (اخد نيكست بتاعها )

    NNode->Prev = TheNodeToInsertAfter; // 3.Set The Prev Ptr Of The New Node To The Current Node (النود الجديده هتاحد مكان الحاليه , فا الحاليه هتبقي مجرد ماضي لجديده)

    if (TheNodeToInsertAfter->Next != nullptr) // 3.If There Is Node After The Current Node
    {
        TheNodeToInsertAfter->Next->Prev = NNode; // Set The Prev Of The Next Node (Of The Current Node) To The New Node
    }

    TheNodeToInsertAfter->Next = NNode; // 4.The New Node After The Current Node
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
    InsetAtTheBeginning(Head, 40);
    InsetAtTheBeginning(Head, 30);
    InsetAtTheBeginning(Head, 10);
    InsetAtTheBeginning(Head, 5);

    cout << "\nBefore Inserting After\n";
    PrintNextNode(Head);

    Node *FindTheNode = Find(Head, 30);
    InsertAfter(FindTheNode, 20);

    cout << "\nAfter Inserting After\n";
    PrintNextNode(Head);
}