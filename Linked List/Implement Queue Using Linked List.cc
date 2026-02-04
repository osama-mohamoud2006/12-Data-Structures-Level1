#include <iostream>
using namespace std;

class Node
{
private:
    Node *Ptr;
    int Value;

public:
    Node()
    {
        Ptr = nullptr;
        Value = 0;
    }
    void SetTheAddressForTheNextNode(Node *Ptr)
    {
        this->Ptr = Ptr;
    }

    void SetValue(int Value)
    {
        this->Value = Value;
    }

    // Get
    int GetValue() { return Value; }
    Node *GetTheAddressOfNextNode() { return this->Ptr; }
};


template <class T>
class clsLinkedListUnderlying
{

public:
    static void InsertElementToTheLastNode(Node *&Head, T value)
    {

        Node *NNode = new Node();
        NNode->SetValue(value);

        // it is the first element to push
        if (Head == nullptr)
        {
            Head = NNode;
            NNode->SetTheAddressForTheNextNode(nullptr);
            return;
        };

        Node *Current = Head;
        while (Current->GetTheAddressOfNextNode() != nullptr)
        {
            Current = Current->GetTheAddressOfNextNode(); // move the current ptr to another node
        };

        Current->SetTheAddressForTheNextNode(NNode); // set the address of next node to new node instead of null (linking the nodes together)

        NNode->SetTheAddressForTheNextNode(nullptr);
    };



};

template <class T>
class QueueInterface // Abstract Class - Contract
{
    virtual void push() = 0;
    virtual void pop() = 0;
    virtual T front() = 0;
    virtual T back() = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
};

template <class T>
class queue : private QueueInterface<T>
{
private:
    Node *Head;
    int count;

public:
    queue()
    {
        Head = nullptr;
        count = 0;
    }

    void push(T Element) override
    {
        clsLinkedListUnderlying<T>::InsertElementToTheLastNode(Head, Element);
        count++;
    };


};

int main()
{

}