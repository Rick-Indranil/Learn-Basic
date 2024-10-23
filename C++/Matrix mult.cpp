#include<iostream>
using namespace std;

class mat
{
private:
    int m[20][20],r,c;
public:
    void read();
    void disp();
    friend mat operator*(mat,mat);
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

mat operator*(mat a1,mat a2)
{
    mat a3;
    if(a1.c==a2.r)
    {
        a3.r=a1.r;
        a3.c=a2.c;
        for(int i=0;i<a1.r;i++)
        {
            for(int j=0;j<a2.c;j++)
            {
                a3.m[i][j]=0;
                for(int k=0;k<a1.c;k++)
                {
                    a3.m[i][j]=a3.m[i][j]+(a1.m[i][k]*a2.m[k][j]);
                }
            }
        }
    }
    return a3;
}

int main()
{
    mat t1,t2,t3;
    t1.read();
    t2.read();
    t3=t1*t2;
    cout<<"\n 1st Matrix:"<<endl;
    t1.disp();
    cout<<"\n 2nd Matrix:"<<endl;
    t2.disp();
    cout<<"\n Sum of two matrices:"<<endl;
    t3.disp();
    return 0;
}


