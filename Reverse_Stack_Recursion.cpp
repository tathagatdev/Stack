// Reverse a stack  -Brute force -> Make another stack and push there but it require more memory
/*  Optimal Algorithm (using recursion) 
1.save top of stack in a variable temp and pop it 
2.Repeat the process till the stack becomes empty using recursion and all the popped elements
  are pushed into recursion stack
 3.Now we call InsertAtBottom function using that temp variable and our stack as parameters
    5    1 
    4    2
    3    3 
    2    4
    1    5
*/

#include<iostream>
#include<stack>
using namespace std;

void InsertAtBottom(stack<int> &st,int temp){
    if(st.empty()){
        st.push(temp);
    }
    else{
        
        int elem=st.top();
        st.pop();
        InsertAtBottom(st,temp);
        st.push(elem);
    }
}

void ReverseStack( stack<int> &st){
    if(st.empty())
    {
        return;
    }
    int temp=st.top();
    st.pop();
    ReverseStack(st);
    InsertAtBottom(st,temp);
    
}

int main()
{
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    cout<<"Original Stack:"<<" "<<"1"<<" "<<"2"<<" "<<"3"<<" "<<"4"<<" "<<"5"<<endl;;
    ReverseStack(st);
    cout<<"Reversed Stack:"<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
  return 0;    
    
}