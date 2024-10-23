#include<iostream>
using namespace std;

class arr
{
private:
    int *x;
    int i,j,n;
public:
    arr()
    {
        n=5;
    }
    arr(int k)
    {
        n=k;
    }
    ~arr()
    {
        delete x;
        cout<<"\n destroyed";
    }
    void read();
    void disp();
    friend arr operator+(arr,arr);
};

void arr::read()
{
    cout<<"\n No.s :";
    for(int i=0;i<n;i++)
    {
        cin>>*(x+i);
    }
}

void arr::disp()
{
    cout<<"List of elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<*(x+i)<<endl;
    }
}

arr operator+(arr a1,arr a2)
{
    arr a3;
    int i;
    for(i=0;i<a1.n;i++)
    {
        *(a3.x+i)= *(a1.x+i) + *(a2.x+i);
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
    r=p+q;
    cout<<"\n 1st array: ";
    p.disp();
    cout<<"\n 2nd array: ";
    q.disp();
    cout<<"\n Sum of two array elements: ";
    r.disp();
    return 0;
}
