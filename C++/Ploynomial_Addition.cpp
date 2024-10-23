#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
    public:
        int coef;
        int pw;
        node *next;
};

class Pollynomial
{
private:
    node *start;
public:
    Pollynomial()
    {
        start=NULL;
    }
    void ins(int c,int p);
    void list();
    friend Pollynomial polyadd(Pollynomial,Pollynomial);
    void mul();
};

void Pollynomial::ins(int c,int p)
{
    int i;
    node *cur,*x;
    cur=new node();
    cur->coef=c;
    cur->pw=p;
    cur->next=NULL;
    if(start==NULL)
     {
          start=cur;
          return;
     }
     x=start;
     while(x->next!=NULL)
     {
          x=x->next;
     }
     x->next=cur;
}

void Pollynomial::list()
{
    node*c;
    cout<<"\neq= ";
    for(c=start;c->next!=NULL;c=c->next)
    {
        cout<<c->coef<<"^"<<c->pw<<"+";
    }
    cout<<c->coef<<"^"<<c->pw<<endl;
}

Pollynomial polyadd(Pollynomial p1, Pollynomial p2)
{
    Pollynomial f3;
    node *f1,*f2;
    f1=p1.start;
    f2=p2.start;
    while(f1!=NULL && f2!=NULL)
    {
         if(f1->pw==f2->pw)
         {
              f3.ins(f1->coef+f2->coef,f1->pw);
              f1=f1->next;
              f2=f2->next;
         }
         else if(f1->pw>f2->pw)
         {
              f3.ins(f1->coef,f1->pw);
              f1=f1->next;
         }
         else
         {
              f3.ins(f2->coef,f2->pw);
              f2=f2->next;
         }
    }
    while(f1!=NULL)
    {
         f3.ins(f1->coef,f1->pw);
         f1=f1->next;
    }
    while(f2!=NULL)
    {
         f3.ins(f2->coef,f2->pw);
         f2=f2->next;
    }

    return f3;
}

main()
{
    int n1,n2,n3,k,c,p;
    Pollynomial f1,f2,f3;
    cout<<"\nenter no. of nodes of 1st list: ";
    cin>>n1;
    for(k=1;k<=n1;k++)
    {
       cout<<"\n coef: ";
       cin>>c;
       cout<<"\n pow: ";
       cin>>p;
       f1.ins(c,p);
    }
    cout<<"\n enter no. of nodes of 2nd list: ";
    cin>>n2;
    for(k=1;k<=n2;k++)
    {
       cout<<"\n coef: ";
       cin>>c;
       cout<<"\n pow: ";
       cin>>p;
       f2.ins(c,p);
    }
    f1.list();
    f2.list();
    f3=polyadd(f1,f2);
    f3.list();
}


