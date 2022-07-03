// Infix to Postfix
/*    Algorithm
  1.Iterate over string from i=0 to i<s.length()
  2. Whenever encounter operand print it into postfix expression
  3. Whenever encounter '(' push into stack 
  4.Whenever encounter operator with 
                   Higher Precedence than previous operators present in stack ---Push into stack
                   Lower Precedence than previous operatos present ---  Pop and print the higher precedence once 
                                                                         and push lower one into stack
    5.Whenever encountern ')' pop stack  until '(' and print elemesnts
    6.When iteration is finished and stack is not empty pop and print them into expression
      
      Eg.   (a-b/c)*(a/k-l)  ---->  abc/-ak/l-*  */
      
      #include<iostream>
      #include<stack>
      #include<string>
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
      
      string InfixToPostfix(string s){
          string res;
          stack<char> st;
          for(int i=0;i<s.length();i++){
              if((s[i]>='a' and s[i]<='z')  or (s[i]>='A' and s[i]<='Z')){
              res+=s[i];
              }
              else if(s[i]=='('){
                  st.push(s[i]);
              }
              else if(s[i]==')'){
                  while(!st.empty() and st.top()!='('){
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
             
          return res;
      }
      int main()
      {
          string s="(a-b/c)*(a/k-l)";
          cout<<"Postfix Expression is :"<<endl<<InfixToPostfix(s);
          return 0;
          }
      
                   
                   