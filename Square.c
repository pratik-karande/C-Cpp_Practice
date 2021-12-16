#include<stdio.h>
int main()
{
    int d1[2],d2[2],d3[2],d4[2];
    printf("enter co-ordinates of point 1\n");
    for(int i=0;i<2;i++)
    {
        scanf("%d",&d1[i]);
    }
    printf("enter co-ordinates of point 2\n");
    for(int i=0;i<2;i++)
    {
        scanf("%d",&d2[i]);
    }
    printf("enter co-ordinates of point 3\n");
    for(int i=0;i<2;i++)
    {
        scanf("%d",&d3[i]);
    }
    printf("enter co-ordinates of point 4\n");
    for(int i=0;i<2;i++)
    {
        scanf("%d",&d4[i]);
    }
    int distD1= (d1[0] - d2[0])*(d1[0] - d2[0]) + (d1[1] - d2[1])*(d1[1] - d2[1]);
    int distD2= (d2[0] - d3[0])*(d2[0] - d3[0]) + (d2[1] - d3[1])*(d2[1] - d3[1]);
    int distD3= (d3[0] - d4[0])*(d3[0] - d4[0]) + (d3[1] - d4[1])*(d3[1] - d4[1]);
    int distD4= (d4[0] - d1[0])*(d4[0] - d1[0]) + (d4[1] - d1[1])*(d4[1] - d1[1]);
    if(distD1==distD2==distD3==distD4)
    {
        printf("YES it is square");
    }
    else{
        printf("NO it is not square");
    }
   
    return 0;
}