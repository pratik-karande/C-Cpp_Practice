#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}
 
// Function to perform arithmetic operations.
int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}
 
// Function that returns value of
// expression after evaluation.
int evaluate(string tokens){
    int i;
     
    // stack to store integer values.
    stack <int> values;
     
    // stack to store operators.
    stack <char> ops;
     
    for(i = 0; i < tokens.length(); i++){
         
 
        if(isdigit(tokens[i])){
            int val = 0;
             
            // There may be more than one
            // digits in number.
            while(i < tokens.length() &&
                        isdigit(tokens[i]))
            {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
             
            values.push(val);
       
              i--;
        }
         

        else
        {
           
            while(!ops.empty() && precedence(ops.top())
                                >= precedence(tokens[i])){
                int val2 = values.top();
                values.pop();
                 
                int val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
             
            // Push current token to 'ops'.
            ops.push(tokens[i]);
        }
    }
     
    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while(!ops.empty()){
        int val2 = values.top();
        values.pop();
                 
        int val1 = values.top();
        values.pop();
                 
        char op = ops.top();
        ops.pop();
                 
        values.push(applyOp(val1, val2, op));
    }
     
    // Top of 'values' contains result, return it.
    return values.top();
}
int main()
{
    int a,b,c,d;
    char arr[]={'/','*','+','-'};
    cout<<"enter numbers"<<endl;
    cin>>a>>b>>c>>d;
    int count=0;
    for(int i=0;i<4;i++)
    {
        
        for(int j=0;j<4;j++)
        {
             
             for(int k=0;k<4;k++)
            {
              // string sExpression = "C";
               string  sExpression = std::to_string(a)+arr[i]+std::to_string(b)+arr[j]+std::to_string(c)+arr[k]+std::to_string(d);
                cout<<std::to_string(a)<<arr[i]<<std::to_string(b)<<arr[j]<<std::to_string(c)<<arr[k]<<std::to_string(d)<<" = "<<evaluate(sExpression)<<endl;
                count++;

                
            }
        }
    }
    cout<<count;
    return 0;
}