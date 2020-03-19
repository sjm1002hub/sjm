#include<iostream>
using namespace std;
class CTime
{    public:
     int date()
	 { 
		 if(year%4==0&&year%100!=0||year%400==0)
			 return 0;
		 else return 1;

	 }
	 int time()
	 {     
		 if(hour>23||minute>59||second>59)
			 return 0;
		 else return  1;
 }
     CTime(int y,int m, int d,int h=0,int mi=0,int s=0);

    ~CTime( )
{  cout<<"析构函数被调用"<<endl;}
      CTime(CTime &p)
{    year=p.year;month=p.month;  day=p.day;
    hour=p.hour;minute=p.minute;second=p.second;
   cout<<"拷贝构造函数被调用"<<endl;
}
   void showTime( )
{
  cout<<year<<"/"<<month<<"/"<<day<<" "<<hour<<":"<<minute<<":"<<second<<endl;
 
}
    int isvalid( ) ;
    int dayDiff(CTime t );
private:
   int year,month,day,hour,minute,second;
};
CTime:: CTime(int y,int m, int d,int h,int mi,int s)
{    int k=1,n=1; 
       year=y; month=m;day=d;
	   hour=h;minute=mi;second=s;
 if(hour<24&&minute<=59&&minute<=59) n=0;
 switch(month)
    { case 1: case 3: 
	case 5: case 7:
	case 8:case 10: case 12:
	if(day>=1&&day<=31) k=0;	break;
	case 4:case 6: case 9:case 11:
		if(day>=1&&day<=30) k=0;break;
    case 2: if(date()&&day>=1&&day<=28) k=0;
			 else if(!date()&&day>=1&&day<=29) k=0;break;
    
	}
	if(k&&n) cout<<"date and time error!"<<endl;
	else if(k&&!n)  cout<<"date error!"<<endl;
	else if(!k&&n)   cout<<"time error!"<<endl;
	if(k||n)  { year=0;month=0;day=0;
	       hour=0;minute=0;second=0;}
	   cout<<"构造函数被调用"<<endl;

       
}

int CTime::isvalid()
{   
	if(year==0)return 0;
	else return 1;
	




}
int  CTime:: dayDiff(CTime t )
{  
	int sum=0,y1,y2,m1,m2,d1,d2;
  if(year>=t.year) 
 {y1=year;y2=t.year;m1=month;m2=t.month;d1=day;d2=t.day;}
else  {y1=t.year;y2=year;m1=t.month;m2=month;d1=t.day;d2=day;}
if(y1==y2&&m1<m2) { m1=m2;d1=d2;}
  switch(m2)
  { case 1:sum=sum+31;
 case 2:  if(y2%4==0&&y2%100!=0||y2%400==0)    
               sum=sum+29;
             else     sum=sum+28;
 case 3:sum=sum+31;
 case 4:sum=sum+30;
 case 5:sum=sum+31;
 case 6:sum=sum+30;
 case 7:sum=sum+31;
 case 8:sum=sum+31;
 case 9:sum=sum+30;
 case 10:sum=sum+31;
 case 11:sum=sum+30;
case 12:sum=sum+31;break;
case 13:break;
}
if(y1==y2)sum=0;
switch(m1-1)
{  case 12:sum=sum+31;
 case 11:sum=sum+30;
 case 10:sum=sum+31;
 case 9:sum=sum+30;
 case 8:sum=sum+31;
 case 7:sum=sum+31;
 case 6:sum=sum+30;
 case 5:sum=sum+31;
 case 4:sum=sum+30;
case 3:sum=sum+31;
 case 2:  if(y1%4==0&&y1%100!=0||y1%400==0)    
               sum=sum+29;
             else     sum=sum+28;
case 1:sum=sum+31;break;
case 0:break;
}
  
 if(y1==y2) return (sum+d1-1);
 else	 
	{ for(y2=y2+1;y2<y1;y2++)
            {   if(y2%4==0&&y2%100!=0||y2%400==0)
                     sum=sum+366;
			else sum=sum+365;}
 

return (sum+d1-d2);
 }


}
 




int  main() 
{ 
        int  year,  month,  day,  hour,  minute,  second; 
        cin  >>  year  >>  month  >>  day  >>  hour  >>  minute  >>  second; 
        CTime  t1(year,  month,  day,  hour,  minute,  second); 
        t1.showTime(); 
        CTime  t2(2000,  1,  1);  //利用默认形参将时间初始化为00:00:00 
        if  (t1.isvalid())          //如果日期和时间合法，则计算天数 
        { 
                int  days=0; 
                days=t1.dayDiff(t2); 
                cout  <<  "这两天之间相隔了"  <<  days  <<  "天"  <<  endl; 
                days=t2.dayDiff(t1); 
                cout  <<  "这两天之间相隔了"  <<  days  <<  "天"  <<  endl; 
        } 
}
