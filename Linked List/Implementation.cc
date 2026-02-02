#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
    Node *PointerToTheNextNode; // pointer
    T Value;

public:
    Node(T Value)
    {
        this->Value = Value;
        this->PointerToTheNextNode = nullptr;
    }

    // Set
    void SetAddressOfNextNode(Node *TheAddressOfNextNode)
    {
        this->PointerToTheNextNode = TheAddressOfNextNode;
    }
};

int main()
{
    Node<int> *Head = nullptr; // pointer of "Node-class-" data type

    // making objects in heap
    // you should make pointer to access the heap memory
    Node<int> *Node1 = new Node(10);
    Node<int> *Node2 = new Node(20);
    
}