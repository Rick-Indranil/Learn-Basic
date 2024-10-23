#include<iostream>
#include<cmath>
using namespace std;
class Shape
{
    public:
        virtual void area(int s)=0;
};

class Circle : public Shape
{
    private:
        double pi=3.14,area_cir;
    public:
        void area(int r);
};

class Triangle : public Shape
{
    private:
        double area_tri;
    public:
        void area(int a);
};

class Square : public Shape
{
    private:
        double area_sqr;
    public:
        void area(int x);
};

void Circle::area(int r)
{
    area_cir=pi*r*r;
    cout<<"\n Area of circle : "<<area_cir;
}

void Triangle::area(int a)
{
    area_tri=sqrt(3)/4*a*a;
    cout<<"\n Area of Triangle : "<<area_tri;
}

void Square::area(int x)
{
    area_sqr=x*x;
    cout<<"\n Area of square : "<<area_sqr;
}

int main()
{
    Circle c;
    Triangle t;
    Square q;

    c.area(7);
    t.area(4);
    q.area(10);
    return 0;
}

