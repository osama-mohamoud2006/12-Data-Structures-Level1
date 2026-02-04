#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
    Node<T> *Ptr;
    T Value;

public:
    // Node()
    // {
    //     Ptr = nullptr;
    //     Value = 0;
    // }
    void SetTheAddressForTheNextNode(Node *Ptr)
    {
        this->Ptr = Ptr;
    }

    void SetValue(T Value)
    {
        this->Value = Value;
    }

    // Get
    T GetValue() { return Value; }
    Node *GetTheAddressOfNextNode() { return this->Ptr; }
};

template <class T>
class clsLinkedListUnderlying
{

public:
    static bool InsertElementToTheLastNode(Node<T> *&Head, Node<T> *&Tail, T value)
    {

        Node<T> *NNode = new Node<T>();
        NNode->SetValue(value);
        Tail = NNode;

        // it is the first element to push
        if (Head == nullptr)
        {
            Head = NNode;
            Tail = Head;
            NNode->SetTheAddressForTheNextNode(nullptr);
            return true;
        };

        Node<T> *Current = Head;
        while (Current->GetTheAddressOfNextNode() != nullptr)
        {
            Current = Current->GetTheAddressOfNextNode(); // move the current ptr to another node
        };

        Current->SetTheAddressForTheNextNode(NNode); // set the address of next node to new node instead of null (linking the nodes together)
        NNode->SetTheAddressForTheNextNode(nullptr);

        return true;
    };

    static bool DeleteTheFirstNode(Node<T> *&Head, Node<T> *&Tail)
    {
        if (Head == nullptr)
        {
            Tail = nullptr;
            return false; // No Nodes
        };

        if (Head->GetTheAddressOfNextNode() == nullptr)
        {
            Tail = nullptr;
        };

        Node<T> *TheFirstElement = Head;
        Head = Head->GetTheAddressOfNextNode();                // move the head to the next node
        TheFirstElement->SetTheAddressForTheNextNode(nullptr); // cut the link of first node with the second node

        delete TheFirstElement;

        if (Head == nullptr)
        {
            Tail = nullptr;
        }

        return true;
    };

    static T TheLastNodeValue(Node<T> *Tail)
    {
        if (Tail != nullptr)
            return Tail->GetValue();
    };

};

template <class T>
class QueueInterface // Abstract Class - Contract
{
    virtual void push(T Element) = 0; // (Done)
    virtual void pop() = 0;           // (Done)
    virtual T front() = 0;            // (Done)
    virtual T back() = 0;             // (Done)
    virtual int size() = 0;           // (Done)
    virtual bool empty() = 0;
};

template <class T>
class queue : private QueueInterface<T>
{
private:
    Node<T> *Head;
    Node<T> *Tail;
    int count;

public:
    queue()
    {
        Head = nullptr;
        Tail = nullptr;
        count = 0;
    }

    void push(T Element) override
    {
        if (clsLinkedListUnderlying<T>::InsertElementToTheLastNode(Head, Tail, Element))
            count++;
    };

    void pop() override // FIFO
    {
        if (clsLinkedListUnderlying<T>::DeleteTheFirstNode(Head, Tail)) // built-in Under Flow Protection
            count--;
    };

    T front() override
    {
        return (Head != nullptr) ? Head->GetValue() : NULL;
    };

    T back() override
    {
        return clsLinkedListUnderlying<T>::TheLastNodeValue(Tail);
    };

    int size() override
    {
        return this->count;
    };

    bool empty() override
    {
        return (Head == nullptr);
    };
};

int main()
{
    queue<string> Q1;
    Q1.push("1");
    Q1.push("2");
    Q1.push("3");
    Q1.push("Iam The Last4");
    cout << "\nThe Last Element is: " << Q1.back() << endl;
    cout << "the size is: " << Q1.size() << endl;

    cout << "\nThe Queue Elements Are: \n";
    while (!Q1.empty())
    {
        cout << Q1.front() << endl;
        Q1.pop();
    }
    cout << "\nthe size is: " << Q1.size() << endl;
    cout << "\nThe Last Element1 is: " << Q1.back() << endl;
}