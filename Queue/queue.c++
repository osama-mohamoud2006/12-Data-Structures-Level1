#include <iostream>
#include <queue>
using namespace std;

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

    short Index =0; 
    cout<<"Printing All Elements Of Queue\n";
    while (!Q.empty())
    {
        cout<<"\nIndex: "<<Index++<<endl; 
        cout<<Q.front(); // Accessing The First Element In The Queue 
        Q.pop(); // Remove The First Element According To FIFO
    }
}