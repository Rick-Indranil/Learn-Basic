#include<iostream>
using namespace std;
template<class Type,int n>
class arr
{
    private:
        Type a[n];
    public:
        arr();
        void input();
        void rev();
        void list();
};

template<class Type,int n>
arr<Type,n>::arr()
{
    for(int i=0;i<n;i++)
        a[i]=0;
}

template<class Type,int n>
void arr<Type,n>::input()
{
    cout<<"\ntenter nos:";
    for(int i=0;i<n;i++)
        cin>>a[i];
}

template<class Type,int n>
void arr<Type,n>::rev()
{
    int i,j;
    Type t;
    for(i=0,j=n-1;i<n/2;i++,j--)
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
}

template<class Type,int n>
void arr<Type,n>::list()
{
    cout<<"\n List:---"<<endl;
    for(int i=0;i<n;i++)
        cout<<"    "<<a[i];
}

int main()
{
    arr<char,5> s;
    s.input();
    s.list();
    s.rev();
    s.list();
    return 0;
}
