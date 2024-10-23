#include<iostream>
#include<string.h>
using namespace std;
class pattern
{
    public:
        void tri(int a);
        void tri(int b,char c);
        void tri(const char s[20]);
};

void pattern::tri(int a)
{
    for(int i=1;i<=a;i++)
    {
        for(int k=1;k<=a-i;k++)
            cout<<" ";
        for(int j=1;j<=2*i-1;j++)
            cout<<"*";
        cout<<"\n";
    }
}

void pattern::tri(int b,char c)
{
    for(int i=1;i<=b;i++)
    {
        for(int k=1;k<=b-i;k++)
            cout<<" ";
        for(int j=1;j<=2*i-1;j++)
            cout<<c;
        cout<<"\n";
    }
}

void pattern::tri(const char s[20])
{
    int n=strlen(s);
    /*int n=0;
    while(s[n]!='\0')
    {
        n++;
    }*/
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n-i;k++)
            cout<<" ";
        for(int j=0;j<=i;j++)
            cout<<s[j]<<" ";
        cout<<"\n";
    }
}

int main()
{
    pattern p;
    p.tri(4);
    p.tri(4,'a');
    p.tri("hello");

    return 0;
}
