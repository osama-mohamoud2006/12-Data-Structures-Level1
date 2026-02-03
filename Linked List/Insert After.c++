#include <iostream>
using namespace std;

class Node
{
private:
    Node *Ptr;
    int Value;

public:
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

Node *Search(Node *Head, int value)
{
    while (Head != nullptr)
    {
        if (Head->GetValue() == value) // if the current node have the desired value
            return Head;
        Head = Head->GetTheAddressOfNextNode(); // move to the next node
    }
    return nullptr; // if it failed to get the value
};

void InsertAfter(Node *Head, Node *TheNodeToInsertAfter, int value)
{
    if (Search(Head, value) != nullptr) // if the node exists
    {
        //1.create new node
        Node * NNode = new Node(); 
    
        //2.Take The Next Address Of New Node From The 'TheNodeToInsertAfter' 
        NNode->SetTheAddressForTheNextNode(TheNodeToInsertAfter->GetTheAddressOfNextNode());

        //3. The 'TheNodeToInsertAfter' Next Node Will Be The New Node Address
        TheNodeToInsertAfter->SetTheAddressForTheNextNode(NNode); 
     
    }
};

 void PrintList(Node * Head)
 {
    while(Head!=nullptr)
    {
        cout<< Head->GetValue()<<endl;
        Head = Head->GetTheAddressOfNextNode();
    }
 };

void InsertAtBegging(Node * &Head  , int value)
{
    
}

 int main()
 {

 }
