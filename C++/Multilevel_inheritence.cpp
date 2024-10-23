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

class result : public subject              //derived class
{
    private:
        int total,per;
    public:
        result();
        result(int a,const char b[],int x,int y,int z);
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

result::result():subject()
{
}
result::result(int a,const char b[],int x,int y,int z):subject(a,b,x,y,z)
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

void result::msheet()
{
    total=sub1+sub2+sub3;
    per=total/3;
    cout<<"\n Total. : "<<total;
    cout<<"\n Percent. : "<<per;
}

int main()
{
    result s;
    s.stu_read();
    s.sub_read();
    s.stu_disp();
    s.sub_disp();
    s.msheet();

    result t(25,"Ram",80,90,70);
    t.stu_disp();
    t.sub_disp();
    t.msheet();

    return 0;
}
