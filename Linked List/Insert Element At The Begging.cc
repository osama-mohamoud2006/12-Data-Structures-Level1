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

template <typename T>
void InsertElementAtTheBegging(Node<T> *&Head, T Value)
{
    // 1. Create New Node
    Node<T> *NNode = new Node(Value);

    // 2. Take The Address Of Next Node (From The Head)
    NNode->SetAddressOfNextNode(Head);

    // 3. Make The Head Takes The Address Of The New Node (as it is the first Node now)
    Head = NNode;
}

template <typename T>
void PrintAllNodes(Node<T> *Head)
{ 
    while(Head!=nullptr)
    {
      cout<<  Head->GetValue() <<endl; 
      Head= Head->PointerToTheNextNode();
    }
}

int main()
{
    
}