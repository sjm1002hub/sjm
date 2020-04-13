#include  "iostream"
using  namespace  std;
class vehicle
{
public:
  vehicle(int x,int y);
 ~vehicle();
 void run()
{
cout<<"vehicle run"<<endl;
}
  void stop()
{
cout<<"vehicle stop"<<endl;
}
private:
  int maxspeed;
 int weight;
};
vehicle:: vehicle(int x,int y)
{
   maxspeed=x;
    weight=y;
 cout<<"vehicle constructor called. maxspeed:";
cout<<maxspeed<<";"<<"weight"<<weight<<endl;
}
vehicle::~vehicle()
{
cout<<"vehicle destructor called. maxspeed:";
cout<<maxspeed<<";"<<"weight"<<weight<<endl;
}
class bicycle:virtual public vehicle
{
public:
 bicycle(int x,int y,int j);
~bicycle();
private:
 int height;
};
bicycle:: bicycle(int x,int y,int j):vehicle(y,j)
{
height=x;
cout<<"bicycle constructor called. height:"<<height<<endl;
}
bicycle:: ~bicycle()
{
cout<<"bicycle destructor called. height:"<<height<<endl;
}
class motorcar:virtual public vehicle
{
public:
  motorcar(int x,int y,int k);
 ~motorcar();
private:
 int seatnum;
};
motorcar::motorcar(int x,int y,int k):vehicle(y,k)
{
  seatnum=x;
  cout<<"motorcar constructor called. setnum:"<<seatnum<<endl;
}
motorcar::~motorcar()
{
cout<<"motorcar destructor called. setnum:"<<seatnum<<endl;
}
class motorcycle:public bicycle , public motorcar
{
public:
  motorcycle(int x ,int y,int k,int n);
 ~motorcycle();
private:
  
};
motorcycle::motorcycle(int x,int y,int k,int n):
    vehicle(k,n),bicycle(x,k,n),motorcar(y,k,n)
{
 cout<<"motorcycle constructor called"<<endl;
}
motorcycle::~motorcycle()
{
cout<<"motorcycle destructor called"<<endl;
}

int  main(int  argc,  char  *argv[])
{
        motorcycle  m(1,  2,  3,  4);//1表示height，2表示setnum，3表示maxspeed，4表示weight
        m.run();
        m.stop();
        return  0;
}
