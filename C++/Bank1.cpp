#include<iostream>
#include<string.h>
using namespace std;
class account
{
    private:
        int acno;
        char name[20];
    protected:
        int bal;
    public:
        account();
        account(int a,const char b[],int c);
        void read();
        void disp();
};

class savings : public account
{
    private:
        int amt;
    public:
        savings();
        savings(int x,const char y[],int z);
        void deposit();
        void withdraw();
};

account::account()                                              /* DEFAULT CONSTRUCTOR */
{
    acno=0;
    strcpy(name,"");
    bal=0;
}
account::account(int a,const char b[],int c)   /* PARAMETERIZED CONSTRUCTOR */
{
    acno=a;
    strcpy(name,b);
    bal=c;
}
savings::savings():account()
{

}

savings::savings(int x,const char y[],int z):account(x,y,z)
{

}

void account::read()
{
    cout<<"\n Account No. : ";
    cin>>acno;
    cout<<"\n Name : ";
    cin>>name;
    cout<<"\n balance : ";
    cin>>bal;
}

void account::disp()
{
    cout<<"\n Account No. : "<<acno;
    cout<<"\n Name. : "<<name;
    cout<<"\n balance : "<<bal;
}

void savings::deposit()
{
    cout<<"\n deposited Amount :";
    cin>>amt;
    if(amt<100)
    {
        cout<<"\n not possible";
    }
    else
    bal=bal+amt;
    cout<<"\n current balance="<<bal<<endl;
}

void savings::withdraw()
{
    cout<<"\n withdraw Amount :";
    cin>>amt;
    if(bal-amt<1000)
    {
        cout<<"\n not possible";
    }
    else
    bal=bal-amt;
    cout<<"\n current balance="<<bal<<endl;
}

int main()
{
    savings s;
    s.read();
    s.disp();
    s.deposit();
    s.withdraw();

    savings t(1001,"ram",15000);
    t.disp();
    t.deposit();
    t.withdraw();

    return 0;
}
