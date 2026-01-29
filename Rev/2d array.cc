#include <iostream>
#include <string>
using namespace std;

int main()
{
    int TwoD[2][2] ; // 2 Rows * 2 Columns 

TwoD[0][0] =1;
TwoD[0][1] = 2;

TwoD[1][0]=3;
TwoD[1][1] = 4;

for(int i=0; i<2; i++) //r
{
 for(int i2=0; i2<2; i++) {cout<<TwoD[i][i2]<<" ";}
  cout<<endl; // after each row


}



}