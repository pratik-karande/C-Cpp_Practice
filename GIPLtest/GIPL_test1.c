// There is more than one way to split 1 into four unit-fractions. [1 = 1/a + 1/b + 1/c + 1/d, for 
// positive integers a<=b, b<=c, c<=d] 
// Please write a function that enumerates all such sets (a, b, c, d) and print them.

#include<stdio.h>
int gcd(int x,int y) /*Function to find greatest common divisor*/
{ 
     if(x==0)
    {
        return y;
    }
    else
    {
     int i, GCD_Num;   

    for( i = 1; i <= x && i <= y; ++i)  
    {  
        if (x % i ==0 && y % i == 0)  
            GCD_Num = i; /* if x and y is completely divisible by i, the divisible number will be the GCD_Num */  
    }  
    return  GCD_Num ;  
    }
}
int main(){
    for(int i=1;i<=20;i++){
        for(int j=1;j<=20;j++){
            for(int k=1;k<=20;k++){
                for(int m=1;m<=20;m++)
                {
                int a,b,c,d=1;
                int jLcm1=(i*j)/gcd(i,j); /*finding lcm using gcd*/
                int jLcm2=(jLcm1*k)/gcd(k,jLcm1);
                int jLcm3=(jLcm2*m)/gcd(m,jLcm2);
                int jComm_denom=jLcm3; 

                 a= jComm_denom/i;
                 b= jComm_denom/j;
                 c= jComm_denom/k;
                 d= jComm_denom/m;
                    if(a+b+c+d==jComm_denom && i<=j && j<=k && k<=m)
                    {
                        printf("(%d , %d , %d , %d)\n ",i,j,k,m);
                    }
                }
            }
        }
    }
    return 0;
}