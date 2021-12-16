#include<stdio.h>
int gcd(int a,int b){
    if(a==0){
        return b;
    }
        return gcd(b%a,a);
    
}
int main(){
    for(int i=1;i<=20;i++){
        for(int j=1;j<=20;j++){
            for(int k=1;k<=20;k++){
                for(int m=1;m<=20;m++){
                int a,b,c,d=1;
                int lcm1=(i*j)/gcd(i,j);

                int lcm2=(lcm1*k)/gcd(k,lcm1);
                int lcm3=(lcm2*m)/gcd(m,lcm2);
                int common_denominator=lcm3;

                 a= common_denominator/i;
                 b= common_denominator/j;
                 c= common_denominator/k;
                 d= common_denominator/m;
                    if(a+b+c+d==common_denominator && i<=j && j<=k && k<=m){
                         printf("%d %d %d %d\n ",i,j,k,m);
                    }
                //with division
                // int jResult=(1/k)+(1/j)+(1/i);
                // if(jResult==1){
                // printf("%d,%d,%d :%d\n",i,j,k,jResult);
                }
            }
        }
    }
    return 0;
}