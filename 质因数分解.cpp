#include <iostream>
#include <cmath>
using namespace std;

//判断是否为素数
int isPrime(long num)
{
int i;
for(i=2;i<num;i++)
if(num%i==0) break;
if(i==num) return(1);
else  return (0);

}

//计算质因素分解，
void factorization(long n,long a[100 ] ,int & ri
)
{
int   j,m=1;
j=isPrime(n);
if(j)  {ri=m;a[0]=n;}
else  {       for(m=n;m>0; m=m/j)
                  for(j=2;j<n;j++)
                if(m%j==0)  {
                                      a[ri]=j;
                                        ri++;
                                       break;}
                                         




}

    return;
}

int main()
{
    long n;
    long factor[100];
    int numofFactor = 0;
    cin >> n;
    factorization(n, factor, numofFactor);
    for (int i = 0; i < numofFactor; i++)
    {
        cout << factor[i] << " ";
    }
    cout << endl;
    return 0;
}

