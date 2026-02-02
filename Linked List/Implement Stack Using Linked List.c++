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
    Node<T> *NNode = nullptr;

public:
    clsStack()
    {
        Head = nullptr;
        NNode = nullptr;
    };

    void Push(T Element) override
    {
        // 1.create new node
        NNode = new Node(Element);
        // 2. link the new node with the pervioud one (the node that the head had)
        NNode->SetAddressOfNextNode(Head);
        Head = NNode;
    }

    virtual void Pop() override
    {
        if (this->Empty())
            throw std::invalid_argument("UnderFlow!\a");


        Head = Head->AddressOfNextNode(); // Get The Address Of Next Node To Move The Head To It
          Node<T> * Temp = Head ;
          delete Temp ;
    }

    T Top() override
    {
        return Head->GetValue();
    }

    bool Empty() override
    {
        return (this->Head == nullptr);
    }
};

int main()
{
    clsStack<int> Stack1;
    Stack1.Push(10);
    Stack1.Push(20);
    Stack1.Push(30);
    Stack1.Push(40);

    while (!Stack1.Empty())
    {
        cout << Stack1.Top() << endl;
        Stack1.Pop();
    }
}