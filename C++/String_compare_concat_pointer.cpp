#include<iostream>
#include<string.h>
using namespace std;
class string1
{
    private:
        char *s;
        int l;
    public:
        string1()
        {
            l=20;
            s=new char[l];
        }
        string1(const char *str)
        {
            l=strlen(str);
            s=new char[l];
            strcpy(s,str);
        }
        void read();
        void disp();
        friend string1 operator+(string1,string1);
        int operator==(string1);
};

void string1::read()
{
    cout<<"\n String : ";
    cin>>s;
}

void string1::disp()
{
    cout<<"\n String : "<<s;
}

string1 operator+(string1 x1,string1 x2)
{
    int i,j;
    string1 x3;
    for(i=0,j=0;*(x1.s+i)!='\0';i++,j++)
    {
        *(x3.s+j)=*(x1.s+i);
    }
    for(i=0;*(x2.s+i)!='\0';i++,j++)
    {
        *(x3.s+j)=*(x2.s+i);
    }
    *(x3.s+j)='\0';
    return x3;
}

int string1::operator==(string1 x)
{
    int n1=strlen(s);
    int n2=strlen(x.s);
    if(n1!=n2)
        return 0;
    for(int i=0;i<n1;i++)
    {
        if(*(s+i)!=*(x.s+i))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string1 s1("abc");
    //s1.read();
    string1 s2;
    s2.read();
    string1 s3;
    s3=s1+s2;
    s3.disp();

    if(s1==s2)
        cout<<"\n Same";
    else
        cout<<"\n Not same";

    return 0;
}

