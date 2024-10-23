#include<iostream>
using namespace std;
class abs
{
    public:
        virtual void fx()=0;
};

class base
{
    public:
        virtual void show();
};

class derived : public base,public abs
{
    public:
        void show();
        void fx();
};

void base::show()
{
    cout<<"\n show Hello from base : ";
}

void derived::show()
{
    cout<<"\n show Good Evening from derived :";
}

void derived::fx()
{
    cout<<"\n hai from derived:";
}

int main()
{
    base b;
    derived d;

    base *p;
    p=&b;
    p->show();

    p=&d;
    p->show();

    d.fx();
    return 0;
}
