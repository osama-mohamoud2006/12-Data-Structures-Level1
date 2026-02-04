#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
    Node *Ptr;
    T Value;

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
    static void InsertElementToTheLastNode(Node<T> *&Head, T value)
    {

        Node<T> *NNode = new Node();
        NNode->SetValue(value);

        // it is the first element to push
        if (Head == nullptr)
        {
            Head = NNode;
            NNode->SetTheAddressForTheNextNode(nullptr);
            return;
        };

        Node<T> *Current = Head;
        while (Current->GetTheAddressOfNextNode() != nullptr)
        {
            Current = Current->GetTheAddressOfNextNode(); // move the current ptr to another node
        };

        Current->SetTheAddressForTheNextNode(NNode); // set the address of next node to new node instead of null (linking the nodes together)

        NNode->SetTheAddressForTheNextNode(nullptr);
    };

    static void DeleteTheFirstNode(Node<T> *&Head)
    {
        if (Head == nullptr)
            return; // No Nodes

        Node<T> *TheFirstElement = Head;
        Head = Head->GetTheAddressOfNextNode();                // move the head to the next node
        TheFirstElement->SetTheAddressForTheNextNode(nullptr); // cut the link of first node with the second node

        delete TheFirstElement;
    };

    static T TheLastNodeValue(Node<T> *Head)
    {
        while (Head->GetTheAddressOfNextNode() != nullptr) // walkthrough nodes until get the last node
        {
            Head = Head->GetTheAddressOfNextNode(); // move to the next Node
        };

        // The Last Node
        return Head->GetValue();
    }
};

template <class T>
class QueueInterface // Abstract Class - Contract
{
    virtual void push(T Element) = 0; // (Done)
    virtual void pop() = 0;           // (Done)
    virtual T front() = 0;
    virtual T back() = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
};

template <class T>
class queue : private QueueInterface<T>
{
private:
    Node<T> *Head;
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

    void pop() override // FIFO
    {
        clsLinkedListUnderlying<T>::DeleteTheFirstNode(Head); // built-in Under Flow Protection
        count--;
    };

    T front() override
    {
        return Head->GetValue();
    };

    T back() override
    {
        return clsLinkedListUnderlying<T>::TheLastNodeValue();
    };
};

int main()
{
}