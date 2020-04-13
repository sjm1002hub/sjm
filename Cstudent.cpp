#include <iostream>
#include <string>
using namespace std;

class CStudent
{
public:
CStudent(char *n=0,int a=0)
{
   name=n;
  age=a;
  count++;
 if(age==0)
 cout<<"noname is contructing"<<endl;
else cout<<name<<" is contructing"<<endl;

}
~CStudent()
{
count--;
if (age==0)
  cout<<"noname is destructing"<<endl;
else cout<<name<<" is destructing"<<endl;
}
void printname( )
{
 if (age==0) cout<<"name:noname"<<endl;
  else cout<<"name:"<<name<<endl;

}
static int count;
static int getcount()
{
	return count;
}
private:
char *name;

int age;

};
//请在这里初始静态成员变量
int CStudent::count=0;


int main()
{
	cout << "现在有学生" << CStudent::getcount() << endl;
	{
		CStudent stuB[5];
		stuB[4].printname();
		cout << "现在有学生" << CStudent::getcount() << endl;
	}
	cout << "现在有学生" << CStudent::getcount() << endl;
	{
		CStudent stuA[2] = {CStudent("Tom", 3), CStudent("Jerry", 2)};
		for (int i = 0; i < 2; i++)
		{
			stuA[i].printname();
		}
		cout << "现在有学生" << CStudent::getcount() << endl;
	}
	cout << "现在有学生" << CStudent::getcount() << endl;

	return 0;
}

