#include <iostream>
using namespace std;
//请在这里补充类Boat和Car的定义
class Car;
class Boat
{ 
   friend int  totalweight(Boat&  b,Car&  c);
public:
   Boat(int a)
  {
      weight=a;
   }
private:
  int weight;

};
class Car
{ 
   friend int  totalweight(Boat&  b,Car&  c);
public:
   Car(int d)
  {
      weight=d;
   }
private:
  int weight;

};

int totalweight(Boat& b,Car& c)
{
    return b.weight+c.weight;
}
int main()
{
    Boat b(100);
    Car c(200);
    cout<<totalweight( b, c)<<endl;
    return 0;
}


