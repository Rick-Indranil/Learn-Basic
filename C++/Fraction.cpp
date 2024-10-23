#include<iostream>
using namespace std;
class fraction
{
    private:
        int numerator,denominator;
    public:
        fraction();
        void input();
        void disp();
        friend fraction addfrac(fraction,fraction);
        int lcm(int a,int b);
};
fraction::fraction()
{
    numerator=0;
    denominator=0;
}
void fraction::input()
{
    cout<<"\n Enter numerator:";
    cin>>numerator;
    cout<<"\n Enter denominator:";
    cin>>denominator;
}
void fraction :: disp()
{
    cout<<numerator<<"/"<<denominator<<endl;
}
fraction addfrac(fraction f1,fraction f2)
{
    int m,n,x;
    fraction f3;
    x=f3.lcm(f1.denominator,f1.denominator);
    m=x/f1.denominator;
    n=x/f1.denominator;
    f3.numerator=(f1.numerator*m)+(f1.numerator*n);
    f3.denominator=x;
    return f3;
}
int fraction::lcm(int a,int b)
{
    int c,i;
    c=a;
    i=2;
    while(c%b!=0)
    {
        c=a*i;
        i++;
    }
    return c;
}

int main()
{
    fraction p,q,r;
    p.input();
    q.input();
    r=addfrac(p,q);
    p.disp();
    q.disp();
    r.disp();
    return 0;
}

