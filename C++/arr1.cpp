#include<iostream>
using namespace std;

class arr
{
private:
    int x[20],n;
public:
    arr();
    arr(int);
    void read();
    void disp();
    void bubble();
};
arr::arr()
{
    n=5;
}
arr::arr(int k)
{
    n=k;
}

void arr::read()
{
    int i;
    cout<<"\n nos :";
    for(i=0;i<n;i++)
    {
        cin>>x[i];
    }
}

void arr::disp()
{
    int i;
    cout<<"List of elements"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<x[i]<<endl;
    }
}

void arr::bubble()
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(x[j]>x[j+1])
            {
                t=x[j];
                x[j]=x[j+1];
                x[j+1]=t;
            }
        }
    }
}

int main()
{
    int u;
    cout<<"\n How many no :";
    cin>>u;
    arr v(u);
    v.read();
    v.bubble();
    v.disp();
    return 0;
}
