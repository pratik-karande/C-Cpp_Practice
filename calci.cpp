#include<iostream>
using namespace std;

int main(){
    float n1;
    float n2;
    cout<<"Input two numbers: "<<endl;
    cin>>n1>>n2;
    cout<<endl;
    char oper;
    cout<<"Input operator: "<<endl;
    cin>>oper;
    cout<<endl;

    switch (oper)
    {
    case '+':
        cout<<n1+n2<<endl;
        break;
    case '-':
        cout<<n1-n2<<endl;
        break;
    case '*':
        cout<<n1*n2<<endl;
        break;
    case '/':
        cout<<n1/n2<<endl;
        break;

    default:
        cout<<"invalid operator"<<endl;
        break;
    }
    return 0;
}