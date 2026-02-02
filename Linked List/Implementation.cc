#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T Value;
    Node *TheAddressOfTheNextNode; // pointer
};

int main()
{

    // pointers as you know pointers stores the address

    Node<int> *Head = nullptr; // head has the address of the first node (will add later)

    Node<int> *Node1 = nullptr;
    Node<int> *Node2 = nullptr;
    Node<int> *Node3 = nullptr;

    // Create Nodes - objects of class Node - (in heap)
    Node1 = new Node<int>(); // the pointer 'Node1' has the address of object
    Node2 = new Node<int>();
    Node3 = new Node<int>();

    Head = Node1; // head has the address of the first node

    // Assign The Values Of Objects
    Node1->Value = 1;
    Node2->Value = 2;
    Node3->Value = 3;

    // Connect Nodes With Each Other
    Node1->TheAddressOfTheNextNode = Node2;
    Node2->TheAddressOfTheNextNode = Node3 ;
    Node3->TheAddressOfTheNextNode =nullptr; /// as the node 3 is the last node


    // Using Head I Will Access All Elements

    while (Head != nullptr)
    {
        cout<<Head->Value <<endl;  // the value that node 1 has
        Head= Head->TheAddressOfTheNextNode; 
    };

    
}