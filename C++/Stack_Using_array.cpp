#include<iostream>
using namespace std;
template<class Type,int n>
class Stack
{
    private:
        Type a[n];
        int top;
    public:
        Stack()
        {
            top=-1;
        }
        void push(Type d);
        int pop();
        void list();
};

template<class Type,int n>
void Stack<Type,n>::push(Type d)
{
    if(top==n-1)
    {
        cout<<"\nStack is full.";
    }
    else
    {
        top++;
        a[top]=d;
    }
}

template<class Type,int n>
int Stack<Type,n>::pop()
{
    Type y;
    if(top==-1)
    {
        cout<<"\nStack is empty.";
    }
    else
    {
        y=a[top];
        top--;
        return y;
    }
}

template<class Type,int n>
void Stack<Type,n>::list()
{
    int i;
    cout<<"\n top = "<<top<<endl;
    for(int i=top;i>=0;i--)
    {
        cout<<" "<<a[i];
    }
}

int main()
{
    Stack<int,5>s;
    int a,v,p;
    do
    {
        cout<<"\n 1. push";
        cout<<"\n 2. pop";
        cout<<"\n 3. list";
        cout<<"\n 4. exit";
        cout<<"\nEnter your choice: ";
        cin>>v;
        switch(v)
        {
            case 1:
                cout<<"\nEnter element: ";
                cin>>a;
                s.push(a);
                s.list();
                break;
            case 2:
                p=s.pop();
                cout<<"\npopped element: "<<p;
                s.list();
                break;
            case 3:
                s.list();
                break;
        }
    }while(v!=4);
}
