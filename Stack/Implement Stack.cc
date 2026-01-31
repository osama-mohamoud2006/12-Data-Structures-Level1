#include <iostream>
#include <vector>
using namespace std;

// implementing stack using vector (dynamic stack)
// stack --> LIFO

template <class T> // to use the class whit any data type
class clsStack
{
private:
    vector<T> VStack;

public:
    // push
    void Push(T Element)
    {
        VStack.push_back(Element);
    }

    // pop
    void Pop()
    {
        if (this->Empty())
            throw std::invalid_argument("UnderFlow!\a");
        VStack.pop_back();
    }

    // top , the first const to avoid editing on return value
    const T &Top() const //--> read-only function
    {
        if (this->Empty())
            throw std::invalid_argument("Empty Stack!\a");
        return VStack.back();
    }

    // empty
    bool Empty() const //--> read-only function
    {
        return (VStack.empty());
    }

    // swap
    void Swap(clsStack<T> &Stack2)
    {
        clsStack<T> temp = *this; // 1
        *this = Stack2;
        Stack2 = temp;
    }
};

int main()
{
    clsStack<short> Stack1;
    Stack1.Push(10);
    Stack1.Push(20);
    Stack1.Push(30);

    clsStack<short> Stack2;
    Stack2.Push(-1);
    Stack2.Push(-2);
    Stack2.Push(-3);

    Stack1.Swap(Stack2);

    while (!Stack1.Empty())
    {

        cout << Stack1.Top() << endl;
        Stack1.Pop();
    }
    
}