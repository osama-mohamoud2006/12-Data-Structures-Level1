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

Node *Find(Node *Head, int value)
{
    while (Head != nullptr)
    {
        if (Head->GetValue() == value)
            return Head;
        Head = Head->GetTheAddressOfNextNode();
    }
    return nullptr;
};

void DeleteNode(Node *&Head, int value)
{
    Node *CurrentNode = Head;
    Node *Prev = Head;

    if (Head == nullptr)
        return; // No Nodes To Delete

    // it is the first node
    if (Head->GetValue() == value)
    {
        Head = Head->GetTheAddressOfNextNode(); // move the head to the next node as the first node will be deleted

        delete Prev;
        return;
    };

    CurrentNode= Head->GetTheAddressOfNextNode(); // as if you reached here then it isn't the fist node that have the desired value then go to the next node to avoid unnecessary 1 iteration 
    
    while (CurrentNode != nullptr) // if the current node isn't the node that have the desired value
    {
        if (CurrentNode->GetValue() == value)
            break;                                            // exit the loop if you got the desired value
        Prev = CurrentNode;                                   // the prev node was the current node (previously)
        CurrentNode = CurrentNode->GetTheAddressOfNextNode(); // move to the next node
    };

    // If The Node Exists
    if (CurrentNode != nullptr)
    {
        Prev->SetTheAddressForTheNextNode(CurrentNode->GetTheAddressOfNextNode()); // the next address for prev will be the next of current

        CurrentNode->SetTheAddressForTheNextNode(nullptr);
        delete CurrentNode;
    };
};

void InsertAtTheEnd(Node *&Head, int value)
{

    Node *NNode = new Node();
    NNode->SetValue(value);

    // if it is the first inserted node
    if (Head == nullptr)
    {
        Head = NNode;
        return;
    };

    Node *CurrentNode = Head;
    while (CurrentNode->GetTheAddressOfNextNode() != nullptr)
    {
        CurrentNode = CurrentNode->GetTheAddressOfNextNode(); // move to the next node
    }

    // if the node next address is null (the last node)
    CurrentNode->SetTheAddressForTheNextNode(NNode);
    NNode->SetTheAddressForTheNextNode(nullptr);
};

void PrintList(Node *Head)
{
    while (Head != nullptr)
    {
        cout << Head->GetValue() << endl;
        Head = Head->GetTheAddressOfNextNode();
    }
}

int main()
{
    Node *Head = nullptr;
    InsertAtTheEnd(Head, 10);
    InsertAtTheEnd(Head, 20);
    InsertAtTheEnd(Head, 30);
    InsertAtTheEnd(Head, 40);

    cout << "\nBefore Deleting Any Node\n";
    PrintList(Head);

    cout << "\nAfterDeleting a Node\n";
    DeleteNode(Head, 10);
    PrintList(Head);
}