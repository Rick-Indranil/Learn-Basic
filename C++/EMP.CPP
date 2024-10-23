#include<iostream>
#include<string.h>
using namespace std;
class emp
{
    private:
        int empno,sal;
        char ename[20];
    public:
        emp();                                              /* DEFAULT CONSTRUCTOR */
        emp(int,const char s1[],int);        /* PARAMETERIZED CONSTRUCTOR */
        void read();
        void disp();
};
emp::emp()                                              /* DEFAULT CONSTRUCTOR */
{
    empno=0;
    strcpy(ename,"");
    sal=0;
}
emp::emp(int a,const char s1[],int b)   /* PARAMETERIZED CONSTRUCTOR */
{
    empno=a;
    strcpy(ename,s1);
    sal=b;
}
void emp::read()
{
    cout<<"\n Employee No. : ";
    cin>>empno;
    cout<<"\n Employee Name : ";
    cin>>ename;
    cout<<"\n Salary : ";
    cin>>sal;
}
void emp::disp()
{
    cout<<"\n Employee No. : "<<empno;
    cout<<"\n Employee Name. : "<<ename;
    cout<<"\n Salary : "<<sal;
}
int main()
{
    emp e;
    e.read();
    e.disp();

    emp f(2,"Sam",5000);
    f.disp();

    return 0;
}
