// Infix to Prefix
/*    Algorithm
      1.Reverse the Expression
      2.InfixToPostfix(); but since we reversed 
      our string we will consider {')' as '('} and {'(' as ')'}
      3.Again reverse the expression 
      
      Eg.   (a-b/c)*(a/k-l)  ---->  *-a/bc-/akl  */
      
      #include<iostream>
      #include<stack>
      #include<string>
      #include<algorithm>
      using namespace std;
      
      int Precedence(char c)
      {
          if(c=='+' or c=='-'){
              return 1;
          }
          else if(c=='*' and c=='/'){
              return 2;
          }
          else if(c=='^'){
              return 3;
          }
          else{
              return -1;
          }
      }
      
      string InfixToPrefix(string s){
          reverse(s.begin(),s.end());
          string res;
          stack<char> st;
          
          for(int i=0;i<s.length();i++){
              if((s[i]>='a' and s[i]<='z')  or (s[i]>='A' and s[i]<='Z')){
              res+=s[i];
              }
              else if(s[i]==')'){
                  st.push(s[i]);
              }
              else if(s[i]=='('){
                  while(!st.empty() and st.top()!=')'){
                  res+=st.top();
                  st.pop();
                  }
                  if(!st.empty())
                  {
                      st.pop();
                      
                  }
                  
                }
                else{
                    while(!st.empty() and Precedence(st.top())>Precedence(s[i]))
                    {
                        res+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
           }    
                while(!st.empty()){
                    res+=st.top();
                    st.pop();
                }
                reverse(res.begin(),res.end());
             
          return res;
      }
      int main()
      {
          string s="(a-b/c)*(a/k-l)";
          cout<<"Prefix Expression is :"<<endl<<InfixToPrefix(s);
          return 0;
          }
      
                   
                   