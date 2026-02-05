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

    // Get
    T GetValue() const
    {
        return this->Value;
    }

    Node *AddressOfNextNode() const
    {
        return PointerToTheNextNode;
    }
};

int main()
{
    Node<int> *Head = nullptr; // pointer of "Node-class-" data type

    // making objects in heap
    // you should make pointer to access the heap memory
    Node<int> *Node1 = new Node(10);
    Node<int> *Node2 = new Node(20);
    Node<int> *Node3 = new Node(30);

    Head = Node1; // make the Head have the address of Node1

    // Connecting Nodes With Each Other
    Node1->SetAddressOfNextNode(Node2);
    Node2->SetAddressOfNextNode(Node3);
    Node3->SetAddressOfNextNode(nullptr);

    Node<int> *Temp = Head; // Temp Pointer to have the value(the address of Node1) to avoid changing the Head value

    while (Temp != nullptr) // nullptr --> means the last Node
    {
        cout << Temp->GetValue() << "\n";
        Temp = Temp->AddressOfNextNode();
    }
    delete Temp; // deallocate 
}