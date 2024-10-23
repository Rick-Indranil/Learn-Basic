#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
using namespace std;
class student
{
    private:
        int rno;
        char name[20];
    public:
        student()
        {
            strcpy(name,"\0");
            rno=0;
        }
        student(int r,char *n)
        {
            rno=r;
            strcpy(name,n);
        }
        int getID()
        {
            return rno;
        }
        void getdata();
        void disp();
};
void student::getdata()
{
    cout<<"Enter the id:"<<endl;
    cin>>rno;
    cin.get();
    cout<<"Enter the name:"<<endl;
    cin.getline(name,20);
}
void student::disp()
{
    cout<<rno<<setw(10)<<name<<endl;
}
class school
{
    private:
        student z;
        fstream infile;
    public:
        school()
        {
            infile.open("data",ios::in|ios::app|ios::out|ios::binary);
        }
        void append();
        void list();
        void find();
        void del();
};
void school::append()
{
    z.getdata();
    infile.clear();
    infile.seekp(0,ios::end);
    infile.write((char*)&z,sizeof(z));
}
void school::list()
{
    infile.seekg(0,ios::beg);
    cout<<"\n"<<"Roll"<<setw(10)<<"Name"<<endl;
    while(1)
    {
        if(infile.read((char*)&z,sizeof(z))==0)
            break;
        z.disp();
    }
    if(infile.eof())
        infile.clear();
}

void school::find()
{
    int f=1;
    int c;
    cout<<"\n Enter Roll:";
    cin>>c;
    infile.seekg(0,ios::beg);
    while(1)
    {
        if(infile.read((char*)&z,sizeof(z))==0)
            break;
        int n;
        n=z.getID();
        if(n==c)
        {
            f=0;
            cout<<"\n"<<"Roll"<<setw(10)<<"Name"<<endl;
            z.disp();
            break;
        }
    }
    if(f==1)
        cout<<"Not found";
    if(infile.eof())
        infile.clear();
}
void school::del()
{
    int c,f=0;
    fstream inf;
    inf.open("datal",ios::out);

    cout<<"\n Enter Roll:";
    cin>>c;

    infile.seekg(0,ios::beg);
    while(1)
    {
        if(infile.read((char*)&z,sizeof(z))==0)
            break;
        int n;
        n=z.getID();
        if(n!=c)
        {
            inf.clear();
            inf.seekp(0,ios::end);
            inf.write((char*)&z,sizeof(z));
        }
        else
            f=1;
    }
    if(f==0)
        cout<<"Not found";
    if(infile.eof())
        infile.clear();
    infile.close();
    inf.close();
    remove("data");
    rename("datal","data");
    infile.open("data",ios::in|ios::app|ios::out|ios::binary);
}
int main()
{
    school s1;
    int a=1;
    do
    {
        cout<<"1. Insert"<<endl;
        cout<<"2. List"<<endl;
        cout<<"3. Find"<<endl;
        cout<<"4. Delete"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Choice??"<<endl;
        cin>>a;
        switch(a)
        {
            case 1:
                s1.append();
                break;
            case 2:
                s1.list();
                break;
            case 3:
                s1.find();
                break;
            case 4:
                s1.del();
                break;
        }
    }while(a!=5);
    return 0;
}
