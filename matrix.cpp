#include<iostream>
using namespace std;
int main(){
    int r,c,i,j,k,a[10][10],b[10][10],mul[10][10];
    cout<<"enter number of rows= "<<endl;
    cin>>r;
    cout<<"enter number of columns= "<<endl;
    cin>>c;
    cout<<"enter first matrix elements= "<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    cout<<"enter second matrix elements= "<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>b[i][j];
        }
    }
    cout<<"product of the matrix= "<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            mul[i][j]=0;
            for(k=0;k<c;k++){
                mul[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<mul[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}