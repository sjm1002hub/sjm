#include<iostream>
using namespace std;
void dx(char str[10])
{   int i;
     for(i=0;str[i]!='\0';i++)
	  if (str[i]>='A'&&str[i]<='Z')
		str[i]=str[i]+'a'-'A';
}



int main ()
{
	char a[10],b[10];int j,k,m=0,p[30],min,n;
	
	cin>>a;
	cin>>b;
	dx(a);
	dx(b);
	for(j=0;a[j]!='\0';j++)
		for(k=0;b[k]!='\0';k++)

		{   p[m]=abs(a[j]-b[k]);m++;}
		

     min=p[0];
      for(n=1;n<m-1;n++)
	     if(min>p[n])  min=p[n];
	
		cout<<min<<endl;
		return 0;



}