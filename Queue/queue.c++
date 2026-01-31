#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class T> // To use with whatever data type
// i used call by val not by ref to avoid Poping the elements of OG queue
void PrintQueueElements(queue<T> Q)
{
    while (!Q.empty())
    {
        cout << Q.front() << " "; // To Print The Elements
        Q.pop();                  // To Pop The First Element At First Then Pop The Others Untill The Queue Becomes Empty
    }
};


template <class T> // To use with whatever data type
void PrintStackElements(stack<T> Stack)
{
    while (!Stack.empty())
    {
        cout << Stack.top() << " "; // To Print The Top Element 
        Stack.pop();                  // To Pop The Last Element Then Pop The Others Untill The Stack Becomes Empty
    }
};


template <class T> // To use with whatever data type
// i used call by val not by ref to avoid Poping the elements of OG queue
void PushQueueElementsToStack(queue<T> Q)
{
    stack<int> Stack; // LIFO
    while (!Q.empty())
    {
        Stack.push(Q.front()); // push the front element of the queue to the stack 
        Q.pop(); 
    }
}

// FIFO
int main()
{
    queue<short> Q;
    // The First Element Of Queue (the first element that will be removed)
    Q.push(10); // push element to the queue
    Q.push(20);
    Q.push(30);
    Q.push(40);

    cout << "\nThe First Element Of The Queue: " << Q.front(); // 10

    cout << "\nThe Last Element Of The Queue: " << Q.back(); // 40

    cout << "\nThe Size(Num Of Elements in Queue) is: " << Q.size();

    // As Queue is FIFO Behaviour, so you cann't Acessing Elements Randomly
    // Rule: The First In The First Pop So You Should Poping First Element To Access The Second Element And So ON

    // short Index = 0;
    cout << "\n\nPrinting All Elements Of Queue 'Q' (Before Swaping)\n";
    // while (!Q.empty())
    // {
    //     cout<<"\nIndex: "<<Index++<<endl;
    //     cout<<Q.front(); // Accessing The First Element In The Queue
    //     Q.pop(); // Remove The First Element According To FIFO
    // };

    PrintQueueElements(Q);

    // Queue 2
    queue<short> Q2;
    // Add Elements To The Queue
    Q2.push(100);
    Q2.push(200);
    Q2.push(300);

    Q.swap(Q2); // Swap Q elements With Q2 Elements

    cout << "\nPrinting All Elements Of Queue 'Q'(After Swaping)\n";
    PrintQueueElements(Q);

    // Reverse The Queue Elements Using Stack
}