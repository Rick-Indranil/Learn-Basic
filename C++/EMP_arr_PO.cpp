#include<iostream>
#include<string.h>
using namespace std;
class emp
{
    private:
        int empno,sal;
        char ename[20];
    public:
        void read();
        void disp();
        int get_sal()
        {
            return sal;
        }
};


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

class office
{
private:
    emp *x;
    int n;
public:
    office()
    {
        n=3;
        x=new emp[n];
    }
    office(int m)
    {
        n=m;
        x=new emp[n];
    }
    void office_read();
    void office_disp();
    void office_sort();
};

void office::office_read()
{
    int i;
    for(i=0;i<n;i++)
    {
        (x+i)->read();
    }
}
void office::office_disp()
{
    int i;
    for(i=0;i<n;i++)
    {
        (*(x+i)).disp();
    }
}

void office::office_sort()
{
    int i,j;
    emp t;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if((x+j)->get_sal()>(x+j+1)->get_sal())
            {
                t=*(x+j);
                *(x+j)=*(x+j+1);
                *(x+j+1)=t;
            }
        }
    }
}

int main()
{
    int k;
    cout<<"\n how many record ?";
    cin>>k;
    office d(k);
    d.office_read();
    d.office_sort();
    d.office_disp();

    return 0;
}

