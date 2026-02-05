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

int main()
{

    Node *Head = nullptr; // Head at the first Node

    // Create new nodes
    Node *Node1 = new Node(1);
    Node *Node2 = new Node(2);
    Node *Node3 = new Node(3);
    Node *Node4 = new Node(4);

    // Linking nodes together
    Node1->Next = Node2;
    Node2->Next = Node3;
    Node3->Next = Node4;
    Node4->Next = nullptr;

    Node1->Prev = nullptr;
    Node2->Prev = Node1;
    Node3->Prev = Node2;
    Node4->Prev = Node3;

    Head = Node1;

    while (Head != nullptr)
    {
        cout << Head->value << endl;
        Head = Head->Next;
    };
};