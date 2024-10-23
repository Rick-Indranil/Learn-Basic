#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
    public:
        int data;
        node *next;
};

class linklist
{
private:
    node *start;
public:
    linklist()
    {
        start=NULL;
    }
    void insend();
    void list();
    void insbeg();
    void insbet();
    void del();
};

void linklist::insend()
{
    node *c,*cur;
    cur=new node();
    cout<<"\n data :";
    cin>>cur->data;
    cur->next=NULL;

    if(start==NULL)
    {
        start=cur;
        return;
    }
    c=start;
    while(c->next!=NULL)
    {
        c=c->next;
    }
    c->next=cur;
}

void linklist::list()
{
    node *c;
    cout<<endl;
    for(c=start;c!=NULL;c=c->next)
    {
        cout<<c->data<<endl;
    }
}

void linklist::insbeg()
{
    node *cur;
    cur=new node();
    cout<<"\n data :";
    cin>>cur->data;

    cur->next=start;
    start=cur;

}

void linklist::insbet()
{
    int i,p;
    node *c,*cur;
    cur=new node();
    cout<<"\n data:";
    cin>>cur->data;
    cur->next=NULL;

    cout<<"\n Position : ";
    cin>>p;

    i=0;
    for(c=start;c!=NULL;c=c->next)
    {
        i++;
        if(i==p-1)
        {
            cur->next=c->next;
            c->next=cur;
            return;
        }
    }
    cout<<"\n invalid position";
    return;
}

void linklist::del()
{
    int i,p;
    node *c,*t;

    if(start==NULL)
    {
        cout<<"\n list is empty";
        return;
    }

    cout<<"\n Position : ";
    cin>>p;

    if(p==1)
    {
        t=start;
        start=start->next;
        delete t;
        return;
    }

    i=0;
    for(c=start;c!=NULL;c=c->next)
    {
        i++;
        if(i==p-1)
        {
            t=c->next;
            c->next=t->next;
            delete t;
            return;
        }
    }
    cout<<"\n invalid position";
}

int main()
{
    linklist z;
    int v;
    do
    {
        cout<<"\n 1. ins end";
        cout<<"\n 2. ins beg";
        cout<<"\n 3. list";
        cout<<"\n 4. exit";
        cout<<"\n 5. ins bet";
        cout<<"\n 6. del";
        cout<<"\n 1. Enter your choice ?";
        cin>>v;
        switch(v)
        {
            case 1:
                z.insend();
                z.list();
                break;
            case 2:
                z.insbeg();
                z.list();
                break;
            case 3:
                z.list();
                break;
            case 5:
                z.insbet();
                z.list();
                break;
            case 6:
                z.del();
                z.list();
                break;

        }
    }while(v!=4);
}
