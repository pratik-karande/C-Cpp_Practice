#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter number: "<<endl;
    cin>>n;
    int k;
    cout<<"enter k: "<<endl;
    cin>>k;
    int count=0;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
     

    }
    for(int i=0;i<n;i++){
       if(arr[i]>k){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}