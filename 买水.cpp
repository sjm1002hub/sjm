#include<iostream>
using namespace std;
int sh(int m ,int n)
{   int a,b,c,k,f;
   a=m/2;b=n/3;
   c=m%2;k=n%3;
   f=a+b;
   if(f+c<2&&f+k<3)
	   return f;
   else  {
	   f=f+sh(f+c,f+k);
   return f;
   }


}
int main()
{
	int i,sum;
	cin>>i;
	sum=sh(i,i)+i;
	cout<<sum;
	return 0;

}