#include<iostream>
using namespace std;
class time
{
    private:
        int hr,min,sec;
    public:
        time();
        void input();
        void disp();
        friend time addtime(time,time);
};
time::time()
{
    hr=0;
    min=0;
    sec=0;
}
void time::input()
{
    cout<<"\n Enter Time:";
    cin>>hr>>min>>sec;
}
void time :: disp()
{
    cout<<hr<<":"<<min<<":"<<sec<<endl;
}
time addtime(time t1,time t2)
{
    time t3;
    t3.hr=t1.hr+t2.hr;
    t3.min=t1.min+t2.min;
    t3.sec=t1.sec+t2.sec;
    if(t3.sec>=60)
    {
        t3.sec=t3.sec-60;
        t3.min++;
    }
    if(t3.min>=60)
    {
        t3.min=t3.min-60;
        t3.hr++;
    }
    t3.hr=t3.hr%24;
    return t3;
}
int main()
{
    time a,b,c;
    a.input();
    b.input();
    c=addtime(a,b);
    a.disp();
    b.disp();
    c.disp();
    return 0;
}
