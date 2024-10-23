#include<iostream>
#include<string.h>
using namespace std;
class student
{
    private:
        int roll;
        char name[20];
    public:
        student();
        student(int a,const char b[]);
        void stu_read();
        void stu_disp();
};

class subject : public student              //derived class
{
    protected:
        int sub1,sub2,sub3;
    public:
        subject();
        subject(int a,const char b[],int x,int y,int z);
        void sub_read();
        void sub_disp();
};

class additional
{
    protected:
        int add_sub;
    public:
        additional();
        additional(int k);
        void add_read();
        void add_disp();
};

class result : public subject,additional              //derived class
{
    private:
        int total,per;
    public:
        result();
        result(int a,const char b[],int x,int y,int z,int k);
        void msheet();
};

student::student()
{
    roll=0;
    strcpy(name,"");
}
student::student(int a,const char b[])
{
    roll=a;
    strcpy(name,b);
}

subject::subject():student()
{
    sub1=0;
    sub2=0;
    sub3=0;
}
subject::subject(int a,const char b[],int x,int y,int z):student(a,b)
{
    sub1=x;
    sub2=y;
    sub3=z;
}

additional::additional()
{
    add_sub=0;
}
additional::additional(int k)
{
    add_sub=k;
}

result::result():subject(),additional()
{
}
result::result(int a,const char b[],int x,int y,int z,int k):subject(a,b,x,y,z),additional(k)
{
}

void student::stu_read()
{
    cout<<"\n Roll No. : ";
    cin>>roll;
    cout<<"\n Name : ";
    cin>>name;
}
void student::stu_disp()
{
    cout<<"\n Roll No. : "<<roll;
    cout<<"\n Name. : "<<name;
}

void subject::sub_read()
{
    cout<<"\n sub1. : ";
    cin>>sub1;
    cout<<"\n sub2. : ";
    cin>>sub2;
    cout<<"\n sub3. : ";
    cin>>sub3;
}
void subject::sub_disp()
{
    cout<<"\n sub1. : "<<sub1;
    cout<<"\n sub2. : "<<sub2;
    cout<<"\n sub3. : "<<sub3;
}

void additional::add_read()
{
    cout<<"\n Additional subject : ";
    cin>>add_sub;
}
void additional::add_disp()
{
    cout<<"\n Additional subject : "<<add_sub;
}

void result::msheet()
{
    total=sub1+sub2+sub3+add_sub;
    per=total/4;
    cout<<"\n Total. : "<<total;
    cout<<"\n Percent. : "<<per;
}

int main()
{
    result s;
    s.stu_read();
    s.sub_read();
    s.add_read();
    s.stu_disp();
    s.sub_disp();
    s.add_disp();
    s.msheet();

    result t(25,"Ram",80,90,70,60);
    t.stu_disp();
    t.sub_disp();
    t.add_sub_disp();
    t.msheet();

    return 0;
}

