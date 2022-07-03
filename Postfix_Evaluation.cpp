//Postfix Evaluation
/*     Algorithm 
   1.Start iterating  from left of the string
   2. Whenver encounter a operand ,push into std::stack 
   3.Whenevr encounter a operator pop Stack[Top] and Stack[Top-1]
        Store Op2=Stack[Top]
        Store op1=Stack[Top-1]
   4. Perform the Operation between op1 and op2 wuth that operator 
   5.Push the result again inside stack
   6.Repeat the process from  step 1   */
   
#include<iostream>
#include<stack>
#include<string>
#include<math.h>
using namespace std;

int PostfixEvaluation(string s){
    stack<int> st;
    int op2,op1;
      for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' and s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else {
              op2=st.top();
              st.pop();
              op1=st.top();
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
    string s="46+2/5*7+";
    cout<<"Post Fix evaluated ans :"<<endl<<PostfixEvaluation(s);
  return 0;
}