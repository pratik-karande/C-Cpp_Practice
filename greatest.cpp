#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cout<<"enter 4 numbers"<<endl;
    cin>>a>>b>>c>>d;
    if(a>b && a>c&&a>d)
    {
        cout<<a<<" is greatest"<<endl;
    }
    else if(b>c&&b>d){
        cout<<b<<" is greatest"<<endl;
    }
    else if(c>d){
        cout<<c<<" is greatest"<<endl;
    }
    else{
        cout<<d<<" is greatest"<<endl;
    }
    return 0;
}