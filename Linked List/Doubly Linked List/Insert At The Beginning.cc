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
    // 1.Create New Node
    Node *NNode = new Node(value);
    NNode->Next = Head;
    NNode->Prev = nullptr;

    if (Head != nullptr) // there are other nodes
    {
        Head->Prev = NNode; // there is node connected to the head already so i want to set its prev ptr to the new node 
    }

    Head = NNode; // move the head to the new node 
};

int main()
{
    
}