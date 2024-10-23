#include<iostream>
#include<string.h>
using namespace std;
class string1
{
    private:
        char *s;
    public:
        string1()
        {
            s=new char[20];
        }
        string1(int n)
        {
            s=new char[n];
        }
        string1(string1 & t)
        {
            s=new char[strlen(t.s)+1];
            int i=0;
            for(i=0;i<strlen(t.s);i++)
            {
                *(this->s+i)=*(t.s+i);
            }
            *(this->s+i)='\0';
        }
        friend ostream & operator<<(ostream& m, string1& p);
        friend istream & operator>>(istream& m, string1& p);

        friend string1 operator+(string1,string1);
       // void operator=(const char *);
        int operator==(string1);
};

ostream & operator<<(ostream& m, string1& p)
{
    m<<p.s;
    return m;
}

istream & operator>>(istream& m, string1& p)
{
    m>>p.s;
    return m;
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
    string1 s2;
  //  s2="India";

    string1 s1(10);
    cout<<"\n enter string1:";
    cin>>s1;
    cout<<"\n enter string2:";
    cin>>s2;
    cout<<s1<<endl;
    cout<<s2<<endl;

    string1 s3;
    s3=s1+s2;
    cout<<s3<<endl;

    if(s1==s2)
        cout<<"\n Same";
    else
        cout<<"\n Not same";

    return 0;
}


