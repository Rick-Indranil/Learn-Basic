#include<iostream>
#include<string.h>
using namespace std;
class emp
{
    private:
        int empno,sal;
        char ename[20];
    public:
        emp();
        emp(int,const char s1[],int);
        void emp_read();
        int get_sal();
        void emp_disp();
};

class office
{
    private:
        emp x[20];
        int n;
    public:
        office();
        office(int);
        void office_read();
        void office_disp();
        void sorting();
};

emp::emp()
{
    empno=0;
    strcpy(ename,"");
    sal=0;
}
emp::emp(int a,const char s1[],int b)
{
    empno=a;
    strcpy(ename,s1);
    sal=b;
}
void emp::emp_read()
{
    cout<<"\n Employee No. : ";
    cin>>empno;
    cout<<"\n Employee Name : ";
    cin>>ename;
    cout<<"\n Salary : ";
    cin>>sal;
}
int emp::get_sal()
{
    return sal;
}
void emp::emp_disp()
{
    cout<<"\n Employee No. : "<<empno;
    cout<<"\n Employee Name. : "<<ename;
    cout<<"\n Salary : "<<sal;
}

office::office()
{
    n=5;
}
office::office(int p)
{
    n=p;
}
void office::office_read()
{
    for(int i=0;i<n;i++)
		{
			x[i].emp_read();
		}
}
void office::office_disp()
{
    for(int i=0;i<n;i++)
		{
			x[i].emp_disp();
		}
}
void office::sorting()
{
    emp t;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(x[j].get_sal()>x[j+1].get_sal())
            {
                t=x[j];
                x[j]=x[j+1];
                x[j+1]=t;
            }
        }
    }
}

int main()
{
    int u;
    cout<<"\n How many employees :";
    cin>>u;
    office o(u);
    o.office_read();
    o.sorting();
    o.office_disp();
    return 0;
}
