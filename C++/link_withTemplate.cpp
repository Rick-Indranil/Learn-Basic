#include<iostream>
#include<stdlib.h>
using namespace std;
template<class Type>
class node
{
    public:
        Type data;
        node *next;
};

template<class Type>
class linklist
{
private:
    node<Type> *start;
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

template<class Type>
void linklist<Type>::insend()
{
    node<Type> *c,*cur;
    cur=new node<Type>();
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

template<class Type>
void linklist<Type>::list()
{
    node<Type> *c;
    cout<<endl;
    for(c=start;c!=NULL;c=c->next)
    {
        cout<<c->data<<endl;
    }
}

template<class Type>
void linklist<Type>::insbeg()
{
    node<Type> *cur;
    cur=new node<Type>();
    cout<<"\n data :";
    cin>>cur->data;

    cur->next=start;
    start=cur;

}

template<class Type>
void linklist<Type>::del()
{
    Type i,p;
    node<Type> *c,*t;

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
    linklist<char> z;
    int v;
    do
    {
        cout<<"\n 1. ins end";
        cout<<"\n 2. ins beg";
        cout<<"\n 3. list";
        cout<<"\n 4. exit";
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
            case 6:
                z.del();
                z.list();
                break;

        }
    }while(v!=4);
}
