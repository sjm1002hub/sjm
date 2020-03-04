#include<iostream>
using namespace std;
int main()
{
	char a[1][8];int i,j,k,m;
	for(i=0;i<8;i++)
		cin>>a[0][i];
	for(i=0;i<8;i++)
	{
		if ( a[0][i]=='*')
			k=i;
	}
   for(j=1;j<9;j++)
	{  m=0;
		for(i=0;i<8;i++)
		if(a[0][i]!=j+'0')
			  m++;
      
		if (m==8) {a[0][k]=j+'0';break;}
   }
   for(i=0;i<8;i++)
	 if(a[0][k]-a[0][i]==k-i&&k!=i)
	 { m=0;break;}
	 else m=1;
	  
   if (m)  cout<<j;
   else
	  cout<<"No Answer";
}