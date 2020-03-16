#include  <iostream> 
#include  <iomanip> 
using  namespace  std; 
#include<string.h>


class Account
{       
  public :
 void init ( char f1[], char n1[],char s1[],int a1,double m1)
             {   
			f=f1;n=n1;s=s1;a=a1;
			if(m1*100-(int)(m1*100)>=0.1) 
			{cout<<"您输入的金额不合法"<<endl;  m=0;}
			else
				m=m1;


		}
		void printmoney( )
		{   

                                                                   
   cout<<n<<"的存款为"<<fixed<<setprecision(2)<<m<<endl;
                                                


		}
		void deposit(double d)
		{    
		     if (d*100-(int)(d*100)>=0.01) 
          cout<<"您输入的金额不合法"<< endl;
                                             
			 else m=m+d;

		}
		void withdraw(double w)
		{  
  if (w*100-(int)(w*100)>=0.1) cout<<"您输入的金额不合法"<<endl;
   else if(w>m) cout<<"您的存款余额不足"<<endl;
                                                  
           else  m=m-w;
		}
private: char* f;char* n;char* s;int a;double m;

};


int  main() 
{ 
        Account  tom; 
        tom.init("32020320011001876X",  "Tom  Black",  "男",  19,  2000.89); 
        tom.printmoney();//输出：Tom  Black的存款为2000.89 
        tom.deposit(89.471);//输出：您输入的金额不合法 
        tom.printmoney();//输出：Tom  Black的存款为2000.89 
        tom.deposit(10000); 
        tom.printmoney();//输出：Tom  Black的存款为12000.89 
        tom.withdraw(10001); 
        tom.printmoney();//输出：Tom  Black的存款为1999.89 
        tom.withdraw(10000.123);//输出：您输入的金额不合法 
        tom.printmoney();//输出：Tom  Black的存款为1999.89 
        tom.withdraw(10000.9);//输出：您的存款金额不足 
        tom.printmoney();//输出：Tom  Black的存款为1999.89 
        Account  jerry; 
        jerry.init("320203200910116569",  "Jerry  Black",  "女",  11,  100.956);//输出：您输入的金额不合法 
        jerry.printmoney();//输出：Jerry  Black的存款为0.00 
}
