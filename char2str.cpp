#include<iostream>
using namespace std;
int main(){
    char arr[]={'a','b','c','d'};
    int n=sizeof(arr)/sizeof(char);
    string j="";
    int i;
    for(i=0;i<n;i++){
        j=j+arr[i];
    }
    cout<<j<<endl;
    return 0;
}