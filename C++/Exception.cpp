#include<iostream>
#include<conio.h>
using namespace std;
class calc
{
        float r;
    public:
        void div(int a,int b);
};
void calc::div(int a,int b)
{
    try
    {
        if(b==0)
            throw "divide by zero";
        r=(float)a/b;
        throw r;
    }
    catch(const char *s)
    {
        cout<<s<<endl;
    }
    catch(float t)
    {
        cout<<"\n divide result is"<<t;
    }
}
main()
{
    int x,y;
    calc c;
    cout<<"\n enter the value of two variables:";
    cin>>x>>y;
    c.div(x,y);
}
