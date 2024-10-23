/*
    fstream
    ofstream -> write
    ifstream -> read
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;
class rec
{
    private:
        char name[20];
        char tel[20];
    public:
        void read()
        {
            char c;
            ofstream f;
            f.open("info.txt",ios::app);
            do
            {
                cout<<"\n Name : ";
                cin>>name;
                cout<<"\n Telephone : ";
                cin>>tel;
                f<<"\t"<<name<<"\t"<<tel<<endl;
                cout<<"\n do you want to continue?(y/n) ";
                cin>>c;
            }while(c!='n');
            f.close();
        }

        void disp()
        {
            ifstream in("info.txt");
            cout<<"\n"<<"name"<<"\t"<<"telephone";
            in>>name>>tel;
            while(in)
            {
                cout<<"\n"<<name<<"\t"<<tel;
                in>>name>>tel;
            }
            in.close();
        }
        void find()
        {
            char c[10];
            int f=1;
            ifstream in("info.txt");
            cout<<"\n"<<"name:";
            cin>>c;
            while(in)
            {
                in>>name>>tel;
                if(strcmp(name,c)==0)
                {
                    f=0;
                    cout<<"\n"<<name<<"\t"<<tel;
                    break;
                }
            }
            if(f==1)
                cout<<"Not found";
            in.close();
        }

        void del()
        {
                char c[10];
                int f=1;
            ifstream in("info.txt");
            ofstream t("temp.txt");
            cout<<"\n"<<"name:";
            cin>>c;
            in>>name>>tel;
            while(in)
            {
                if(strcmp(name,c)!=0)
                {
                    t<<name<<"\t"<<tel<<endl;
                }
                in>>name>>tel;
            }
            in.close();
            t.close();
            remove("info.txt");
            rename("temp.txt","info.txt");
        }
};

main()
{
    int n;
    rec v;

    do
    {
        cout<<"\n The Menu(press 5 to exit):=";
        cout<<"\n 1. read\n";
        cout<<"\n 2. disp\n";
        cout<<"\n 3. find\n";
        cout<<"\n 4. delete\n";
        cout<<"\n Choice ?";
        cin>>n;
        switch(n)
        {
            case 1:
                v.read();
                break;
            case 2:
                v.disp();
                break;
            case 3:
                v.find();
                break;
            case 4:
                v.del();
                break;
        }
    }while(n!=5);
}
