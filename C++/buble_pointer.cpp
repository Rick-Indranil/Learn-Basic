#include<iostream>
#include<stdio.h>
using namespace std;
class arr
{
private:
    int *x;
    int j,i,n;
public:
    arr ()
    {
        n=5;
        x=new int[n];
    }
    arr(int m)
    {
        n=m;
        x=new int[n];
    }
    ~arr()
    {
        delete x;
        cout<<"\n destroyed";
    }
    void read();
    void disp();
    void bubblesort();
};
void arr::read()
{
    cout<<"\n enter nos : \n";
    for(int i=0;i<n;i++)
    {
        cin>>*(x+i);
    }
}
void arr::disp()
{
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<*(x+i)<<endl;
    }
}
void arr::bubblesort()
{
    int t,i,j;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(*(x+j)>*(x+j+1))
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
    int n;
    cout<<"\n enter no. of input: ";
    cin>>n;
    arr s(n);
    s.read();
    s.disp();
    s.bubblesort();
    s.disp();
    return 0;
}
