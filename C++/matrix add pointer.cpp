#include<iostream>
using namespace std;

class mat
{
private:
    int **m;
    int r,c;
public:
    mat()
	 {
		 r=3;
		 c=3;
		 m=new int*[r];
		 for(int i=0;i<r;i++)
         {
             *(m+i)=new int[c];
         }
	 }
	 mat(const int k,const int n)
	 {
		r=k;
		c=n;
		 m=new int*[r];
		 for(int i=0;i<r;i++)
         {
             *(m+i)=new int[c];
         }
	 }
/*
    ~mat()
    {
        delete m;
        cout<<"\n destroyed";
    }
*/
    void read();
    void disp();
    friend mat operator+(mat,mat);
};
void mat::read()
{
    cout<<"\n Enter elements : ";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>*(*(m+i)+j);
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
            cout<<*(*(m+i)+j)<<"\t";
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
                *(*(a3.m+i)+j)=*(*(a1.m+i)+j)+*(*(a2.m+i)+j);
            }
        }
    }
    return a3;

}



int main()
{
    int r,c;
    cout<<"\n How many rows : ";
    cin>>r;
    cout<<"\n How many columns : ";
    cin>>c;

    mat t1(r,c);
    mat t2(r,c);
    mat t3(r,c);
    t1.read();
    t2.read();
    t3=t1+t2;
    cout<<"\n 1st Matrix:"<<endl;
    t1.disp();
    cout<<"\n 2nd Matrix:"<<endl;
    t2.disp();
    cout<<"\n resultant Matrix:"<<endl;
    t3.disp();
    return 0;
}
