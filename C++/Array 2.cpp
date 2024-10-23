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
    friend arr add(arr,arr,int);
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
    cout<<"\n No.s :";
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

arr add(arr a1,arr a2)
{
    arr a3;
    int i;
    for(i=0;i<a1.n;i++)
    {
        a3.x[i]=a1.x[i]+a2.x[i];
    }
    return a3;
}

int main()
{
    int e;
    cout<<"\n No. of elements in 1st and 2nd arrays: ";
    cin>>e;
    arr p(e),q(e),r(e);
    p.read();
    q.read();
    r=add(p,q);
    cout<<"\n 1st array: ";
    p.disp();
    cout<<"\n 2nd array: ";
    q.disp();
    cout<<"\n Sum of two array elements: ";
    r.disp();
    return 0;
}
