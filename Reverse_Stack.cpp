// Reverse a stack  
/* Brute force -> Make another stack and push there 

    5    1 
    4    2
    3    3 
    2    4
    1    5
*/

#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> st1;
    stack<int> st2;
    st1.push(5);
    st1.push(4);
    st1.push(3);
    st1.push(2);
    st1.push(1);
    cout<<"Original Stack:"<<endl<<"1"<<" "<<"2"<<" "<<"3"<<" "<<"4"<<" "<<"5"<<endl;
    cout<<endl;
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
    }
   
    cout<<"Reversed Stack:"<<endl;
    while(!st2.empty())
    {
        cout<<st2.top()<<" ";
        st2.pop();
    }
  return 0;    
    
}