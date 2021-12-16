#include<iostream>
using namespace std;
class GFG
{
      int result =0;
/* function to multiply two numbers x and y*/
public : int multiply(int x, int y)
{
  
    //  multiplied with anything gives 
    if(y == 0)
    return 0;
 
    // Add x one by one //
    if(y > 0 ){
    result=multiply(x, y-1);
     cout <<result<< endl;
    return (x + result);
    }
   
  

    //the case where y is negative //
    if(y < 0 ){
       result =multiply(x, -y);
       cout << endl <<result;
    }
    return result;
}
};
 
// Driver code
int main()
{
    GFG g;
  //  g.multiply(5, 5);
       int resultFinal =0;
   resultFinal= g.multiply(3, 2);
    cout << endl <<resultFinal;
    //getchar();
    return 0;
}