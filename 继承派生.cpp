#include <iostream>
using namespace std;
const int pi=3.14159;
class Shape
{
    public:
        Shape(int x);
        ~Shape();
       
        int GetID() { return m_ID; }
        void SetID(int val) { m_ID = val; }
        int getArea()
   {
    return 0;
   }
    protected:

    private:
        int m_ID;
};
Shape::Shape(int x)
{
    m_ID=x;
   cout<<"Shape constructor called:"<<m_ID<<endl;
}

Shape::~Shape()
{
    cout<<"Shape destructor called:"<<m_ID<<endl;
}
class Circle : public Shape
{
    public:
        Circle(int x,int j);
        virtual ~Circle();

        int Getr() { return m_r; }
        void Setr(int val) { m_r = val; }
       int getArea()
     {
        return pi*m_r*m_r;
    }
    protected:

    private:
        int m_r;
};
Circle::Circle(int x,int j):Shape(j)
{
  m_r=x;
 cout<<"Circle constructor called:"<<GetID()<<endl;
}

Circle::~Circle()
{
    cout<<"Circle destructor called:"<<GetID()<<endl;
}
class Rectangle : public Shape
{
    public:
        Rectangle(int x,int j,int k);
        virtual ~Rectangle();

         int Geth() { return m_h; }
        void Seth( int val) { m_h = val; }
         int Getw() { return m_w; }
        void Setw( int val) { m_w = val; }
       int getArea()
     {
        return m_h*m_w;
    }
    protected:

    private:
         int m_h;
         int m_w;
};
Rectangle::Rectangle(int x,int j,int k):Shape(k)
{
    m_h=x;m_w=j;
 cout<<"Rectangle constructor called:"<<GetID()<<endl;
}

Rectangle::~Rectangle()
{
    cout<<"Rectangle destructor called:"<<GetID()<<endl;
}

int main()
{
    Shape s(1);//1表示ID
    Circle c(4,2);//4表示半径，2表示ID
    Rectangle r(4, 5,3);//4和5表示长和宽，3表示ID
    cout<<"Shape的面积"<<s.getArea()<<endl;
    cout<<"Circle的面积"<<c.getArea()<<endl;
    cout<<"Rectangle的面积"<<r.getArea()<<endl;
}

