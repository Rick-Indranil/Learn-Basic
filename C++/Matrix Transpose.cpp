 #include<iostream>
using namespace std;

class mat
{
private:
    int m[20][20],r,c;
public:
    void read();
    void disp();
    void transpose();
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

void mat::transpose()
{
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            cout<<m[j][i]<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    mat t1;
    t1.read();
    cout<<"\n Matrix:"<<endl;
    t1.disp();
    cout<<"\n Transpose of matrix:"<<endl;
    t1.transpose();
    return 0;
}


