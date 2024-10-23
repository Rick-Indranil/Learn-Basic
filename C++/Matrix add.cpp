#include<iostream>
using namespace std;

class mat
{
private:
    int m[20][20],r,c;
public:
    void read();
    void disp();
    int operator==(mat);
    friend mat operator+(mat,mat);
};
void mat::read()
{
    cout<<"\n How many rows : ";
    cin>>r;
    cout<<"\n How many columns : ";
    cin>>c;
    cout<<"\n Enter elements : ";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>m[i][j];
        }
    }
    cout<<endl;
}

void mat::disp()
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
}

mat operator+(mat a1,mat a2)
{
    mat a3;
    if(a1.r==a2.r && a1.c==a2.c)
    {
        a3.r=a1.r;
        a3.c=a1.c;
        for(int i=0;i<a1.r;i++)
        {
            for(int j=0;j<a1.c;j++)
            {
                a3.m[i][j]=a1.m[i][j]+a2.m[i][j];
            }
        }
    }
    return a3;
}

int mat::operator==(mat t1)
{
    if(r!=t1.r || c!=t1.c)
        return 0;
    return 1;
}

int main()
{
    mat t1,t2,t3;
    t1.read();
    t2.read();
    t3=t1+t2;
    cout<<"\n 1st Matrix:"<<endl;
    t1.disp();
    cout<<"\n 2nd Matrix:"<<endl;
    t2.disp();
    if(t1==t2)
    {
        cout<<"\n Sum of two matrices:"<<endl;
        t3.disp();
    }
    else
    {
        cout<<"\n Matrices are not same:"<<endl;
    }
    return 0;
}

