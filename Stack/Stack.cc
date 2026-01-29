#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> S1; // template class from STL

    // note : Memory usage depends on the underlying container and stored elements
    S1.push(1); // push the first element to the stack
    S1.push(2);
    S1.push(3);
    S1.push(4);
    S1.push(5);

    // LIFO //
    cout << S1.top() << endl; // will print the last element in the stack

    S1.pop();                  // remove the last element
    cout << S1.size() << endl; // will print the size of stack according to the num of elements in the stack

    // cout<< S1.isfull()<<endl; //class "std::stack<int, std::deque<int, std::allocator<int>>>" has no member "isfull"

    // Print All Elements - As The Stack is LIFO Approach You Cann't Do Random Access To Its Elements LikeArray

    cout<<"\n Printing Stack All Elements\n";
    while (!S1.empty())
    {
        cout << S1.top() << endl;
        S1.pop(); // to remove the top element to access the other elements 
    }
}
