#include <iostream>
#include <string>
using namespace std;

// print from 1 to 10

void PrintToNum(int from=0 , int to=10 )
{
    if(to == 0 ) return; // base case 
    cout<< from <<endl;
    PrintToNum(from=from+1,to=to-1); // recursive call 
}

void PrintText(string Text , int count)
{
    if(count == 0 ) return ; // base case 
    cout<<Text<<endl;
    PrintText(Text,count=count-1);
}

void PrintNumberSperated(int n, int i =0)
{
    
    string num = to_string(n);
    if(i > num.length() -1 ) return ; 
    cout<< num[i]<<" "; 
    PrintNumberSperated(n , i = i+1 ); // increment the index 
}

int main()
{
    //PrintToNum(1,10);
   // PrintText("I Love Me",3);
   PrintNumberSperated(12345);
}