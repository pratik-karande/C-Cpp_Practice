//Given an integer N, output how many 1’s are present in the binary representation of N.
#include<iostream>
using namespace std;
void DecimalToBinary(int n)
{
    int binaryNumber[100], num=n;
    int i=0;
    int counter=0;

    while(n>0)
    {
    binaryNumber[i]=(n%2);
    cout<<binaryNumber[i]<<endl;
    if(binaryNumber[i]==1){
        counter++;
    }

    n=n/2;
    i++;
    }
    cout<<counter<<endl;
}
int main(){
    DecimalToBinary(15);
    return 0;
}