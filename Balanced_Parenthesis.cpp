// Balanced Parenthesis
#include<iostream>
#include<stack> 
#include<string>
using namespace std;

bool isvalid(string s)
{
    bool ans=true;
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='{' or s[i]=='[' or s[i]== '('){
            st.push(s[i]);
        }
    
    else if(s[i]==')'){
        if(!st.empty() and st.top()=='(')
        {
            st.pop();
        }
        else
        {
            ans=false;
            break;
        }
    }
    else if(s[i]==']'){
        if(!st.empty() and st.top()=='[')
        {
            st.pop();
        }
        else
        {
            ans=false;
            break;
        }
    }
    else if(s[i]=='}'){
        if(!st.empty() and st.top()=='{')
        {
            st.pop();
        }
        else
        {
            ans=false;
            break;
        }
      }
    }
    if(!st.empty())
    {
        return false;
    }
    else{
        return ans;
    }
    
    
}
int main(){
    string s="{[()]}";
    if(isvalid(s))
    {
        cout<<"Balanced Parenthesis";
    }
    else
    {
        cout<<"Invalid";
    }

    return 0;
}
