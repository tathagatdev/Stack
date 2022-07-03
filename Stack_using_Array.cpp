#include<iostream>
#define n 100
using namespace std;
class Stack{
    int top;
    int *arr;
    public:
    Stack()
    {
        top=-1;
        arr= new int[n];
    }
    void Push()
    { int x;
    cout<<"Enter element to be pushed "<<endl;
    cin>>x;
        if(top==n-1)
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            top++;
            arr[top]=x;
            cout<<x<<" "<<"Pushed Sucessfully"<<endl;
        }
    }
    void Pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top--;
            cout<<"Element Popped Sucessfully"<<endl;
        }
    }
    int Top()
    {
         if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
        }
        else{
        return arr[top];
       }
    }
    
    bool isEmpty(){
        if(top==-1)
        {
            return true;
        }
        else{
            return false;
        }
       
    }
};
int main()
{
    Stack s;
    int ch;
    int choice;

    do{
    
        cout<<"Operations performed by Stack"<<endl;
        cout<<"\n1.Push the element \n2.Pop the element \n3.Top element \n4.Is Empty \n5.End"<<endl;
        cout<<" Enter the choice:"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1: s.Push();
                    break;
            case 2: s.Pop();
                    break;
            case 3: cout<<s.Top()<<endl;
                    break;
            case 4: s.isEmpty();
                    break;
            case 5: exit(0);
                    break;

            default: cout<<"Invalid choice!!"<<endl;
        }
        cout<<"Want to continue with other operations \n  Yes-1 \n  No-2 \n"<<endl;;
        cin>>ch;
    }while(ch==1);
    return 0;
}