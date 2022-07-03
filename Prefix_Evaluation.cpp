// Prefix Evaluation 
/*          Algorithm
    1. Start iteraing  from right i.e from i=s.length()-1 to i=0
    2. Follow same process as Postfix Evaluation  
    3.      But while popping 
               save op1=stack[Top]
               save  op2=Stack[Top-1]*/

#include<iostream>
#include<stack>
#include<string>
#include<math.h>
using namespace std;

int PostfixEvaluation(string s){
    stack<int> st;
    int op2,op1;
      for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]>='0' and s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else {
              op1=st.top();
              st.pop();
              op2=st.top();
              st.pop();
              switch(s[i])
              {
                  case '+':  st.push(op1+op2);
                              break;
                  case '-':  st.push(op1-op2);
                              break;
                  case '*':  st.push(op1*op2);
                              break;
                  case '/':  st.push(op1/op2);
                              break;
                  case '^':  st.push(pow(op1,op2));
                              break;
              }
                
            }
            
        }
        return st.top();
}

int main()
{
    string s="-+7*45+20";
    cout<<"Pre Fix evaluated ans :"<<endl<<PostfixEvaluation(s);
  return 0;
}