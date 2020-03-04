#include<iostream>
#include<iomanip>
using namespace std;
struct complex
{  double r;
   double ig;
};
complex de(complex m,complex n)
{  
	complex c;
	c.r=m.r-n.r;
	c.ig=m.ig-n.ig;
	return c;
}

int main()
{
    complex c1,c2,a;
	cin>>c1.r>>c1.ig;
	cin>>c2.r>>c2.ig;
	a=de(c1,c2);
	cout<<fixed<<setprecision(2)<<a.r<<' '<<a.ig<<endl;
	return 0;





}
