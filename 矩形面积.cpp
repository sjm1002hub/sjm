#include  <iostream> 
using  namespace  std; 



 class CPoint
{    public:
   CPoint(CPoint &p)
   {
	   X=p.X;
	   Y=p.Y;
      cout<<"CPoint copy contstructor is called."<<endl;

   }
   CPoint( int x=0 , int y=0);

  int getx( )
{ return X;
}
  int gety()
{  return Y;
}
   private:
         int X ,Y;
};
class CRectangle
{ 
   public:
     CRectangle(int x=0,int y=0,int j=0,int k=0);
    
      CRectangle(CPoint q1,CPoint q2);
       CRectangle(CRectangle &k):one(k.one),two(k.two)
	 {   
            cout<<"CRectangle copy contstructor is called."<<endl;
	 }
      int GetArea( )
{    return (two.gety()-one.gety())*(two.getx()-one.getx());
}
  private:
      CPoint one;
      CPoint two;
 };
 CPoint::CPoint( int x ,int y)
   {     X=x;Y=y;
    cout<<"CPoint contstructor with default value(0,0) is called."<<endl;
   }
CRectangle::CRectangle(int x,int y,int j,int k):one(x,y),two(j,k)
{ if(x==0&&j==0)
 cout<<"CRectangle defualt contstructoris called. "<<endl;
else
 cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;
}
CRectangle:: CRectangle(CPoint q1,CPoint q2):one(q1),two(q2)
{
 cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
}

int  main() 
{ 
        int  a=1,  b=1,  c=6,  d=11; 
        cout<<"#  Define  p1  ######"<<endl; 
        CPoint  p1; 
        cout<<"#  Define  p2  ######"<<endl; 
        CPoint  p2(10,20); 
        cout<<"#  Define  rect1  ######"<<endl; 
        CRectangle  rect1; 
        cout<<"#  Define  rect2  ######"<<endl; 
        CRectangle  rect2(p1,  p2); 
        cout<<"#  Define  rect3  ######"<<endl; 
        CRectangle  rect3(a,  b,  c,  d); 
        cout<<"#  Define  rect4  ######"<<endl; 
        CRectangle  rect4(rect2); 
        cout<<"#  Calculate  area  ######"<<endl; 
        cout  <<  "rect1面积为"  <<  rect1.GetArea()  <<  endl; 
        cout  <<  "rect2面积为"  <<  rect2.GetArea()  <<  endl; 
        cout  <<  "rect3面积为"  <<  rect3.GetArea()  <<  endl; 
        cout  <<  "rect4面积为"  <<  rect4.GetArea()  <<  endl; 
        system("pause"); 
        return  0; 
} 