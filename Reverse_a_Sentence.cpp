//Reverse a sentence
/*   Algorithm
1. just iterate the string till s.length()
2. whenever encounter space then push that word into stack and repeat 
3. print stack elements        */
#include<iostream>
#include<stack>
using namespace std;

void ReverseSentence(string s)
{
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word ;
        
        while(s[i]!=' '  and i<s.length())
        {
            word+=s[i];
            i++;
        }   
        st.push(word);
    }
    while( !st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main()
{
    string s="Hey,how are you doing?";
    cout<<s<<endl;
    ReverseSentence(s);

    return 0;
}