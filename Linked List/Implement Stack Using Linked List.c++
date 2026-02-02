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

template <class T>
// Abstract Class
class clsStackInterface
{

    virtual void Push(T Element) = 0; // push
    virtual void Pop() = 0;           // pop
    virtual T Top() = 0;              // top , the first const to avoid editing on return value
    virtual bool Empty() = 0;
    // virtual void Swap(clsStack<T> Stack2) = 0;
};

template <class T>
class clsStack : private clsStackInterface<T>
{
private:
    Node<T> *Head = nullptr;
    Node<T> *TheLastestNode= nullptr;

public:
    void Push(T Element) override{
        //1.create new node
        Node<T> NNode = new Node(this->Element);
        //2. link the new node with the pervioud one (the node that the head had)
        NNode->SetAddressOfNextNode(Head);
        Head = NNode;
        TheLastestNode= NNode;
    }

     virtual void Pop() override
     {
          Head = Head->AddressOfNextNode(); // Get The Address Of Next Node To Move The Head To It


     }

};