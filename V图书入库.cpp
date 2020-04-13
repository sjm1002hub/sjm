#include  <iostream>
#include<vector>
#include<string>
using  namespace  std;
class  Book
{
public:
        Book();
        virtual ~Book();
        Book(const Book& other);

        unsigned int GetID() { return m_ID; }
        void SetID(unsigned int val) { m_ID = val; }
        unsigned int GetPage() { return m_Page; }
        void SetPage(unsigned int val) { m_Page = val; }
        string GetName() { return m_Name; }
        void SetName(string val) { m_Name = val; }
        string GetIntroduction() { return m_Introduction; }
        void SetIntroduction(string val) { m_Introduction = val; }
        string GetAuthor() { return m_Author; }
        void SetAuthor(string val) { m_Author = val; }
        string GetDate() { return m_Date; }
        void SetDate(string val) { m_Date = val; }

    protected:

    private:
        unsigned int m_ID;
        unsigned int m_Page;
        string m_Name;
        string m_Introduction;
        string m_Author;
        string m_Date;
};

Book::Book()
{
m_ID=0;
}

Book::~Book()
{

}

Book::Book(const Book& other)
{
    m_ID=other.m_ID;
    m_Name=other.m_Name;
    m_Author=other.m_Author;
    m_Introduction=other.m_Introduction;
    m_Date=other.m_Date;
    m_Page=other.m_Page;

}
class  Store
{
	 public:
        Store();
        Store(int n);
        virtual ~Store();
        Store(const Store& other);
		 unsigned int GetCount();
       
        Book findbyID(int ID);
        Book findbyName(string name);
        void in(Book &b);
        void out(string name);
        void printList();
    protected:

    private:
       vector<Book>m_Books;
};

Store::Store()
{
    cout<<"Store default constructor called!"<<endl;
}
Store::Store(int n)
{
      
   vector<Book>m_Books(n);
    cout<<"Store constructor with (int n) called!"<<endl;
}

Store::~Store()
{
     
   cout<<"Store destructor called!"<<endl;
}

Store::Store(const Store& other)
{    for(unsigned int i=0;i<m_Books.size();i++)
     m_Books[i]=other.m_Books[i];
    cout<<"Store copy constructor called!"<<endl;
}
Book Store::findbyName(string name)
{  Book a;unsigned int i;
  for(i=0;i<m_Books.size();i++)
 if(m_Books[i].GetName()==name)

 { a=m_Books[i]; break;}
 if(i==m_Books.size()) a.SetID(0);



return a;
}
Book Store::findbyID(int ID)
{  Book q;unsigned int i;
  for( i=0;i<m_Books.size();i++)
 if(m_Books[i].GetID()==ID)

 {  q=m_Books[i];  break;}

if(i==m_Books.size())  q.SetID(0);
return q;
}
void Store::in(Book &b)
{
	
  m_Books.insert(m_Books.end(),b);

}
void Store::out(string name)
{  
vector<Book>::iterator it;
for(it=m_Books.begin();it!=m_Books.end();it++)
{
	
	if((*it).GetName()==name)
	
	{
		m_Books.erase(it);break;}

}
  
}
 unsigned int Store::GetCount()
 {
	 return m_Books.size();
 }
void Store::printList()
{
 cout<<"There are totally "<<GetCount()<<" Books:"<<endl;
for(unsigned int i=0;i<m_Books.size();i++)
{cout<<"ID="<<m_Books[i].GetID()<<"; ";
cout<<"Name:"<<m_Books[i].GetName()<<"; ";
cout<<"Author:"<<m_Books[i].GetAuthor()<<"; ";
cout<<"Page:"<<m_Books[i].GetPage()<<"; "<<endl;
}

}





int  main()
{
        Store  s;
        Book  b1,b2,b3;
        b1.SetID(1);
        b1.SetName("C++  语言程序设计(第4版)");
        b1.SetAuthor("郑莉");
        b1.SetIntroduction("介绍C++及面向对象的知识");
        b1.SetDate("201007");
        b1.SetPage(529);
        b2.SetID(2);
        b2.SetName("离散数学");
        b2.SetAuthor("左孝凌");
        b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
        b2.SetDate("198209");
        b2.SetPage(305);
        b3.SetID(3);
        b3.SetName("c程序设计");
        b3.SetAuthor("谭浩强");
        b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
        b3.SetDate("201006");
        b3.SetPage(355);

        cout<<"第一本书入库"<<endl;
        s.in(b1);
        cout<<"第二本书入库"<<endl;
        s.in(b2);
        cout<<"第三本书入库"<<endl;
        s.in(b3);
        cout  <<"现有库存书籍数量："<<s.GetCount()  <<  endl;
        cout  <<"查找并出库图书：离散数学"  <<  endl;
        Book  tmpbook=s.findbyName("离散数学");
        if(tmpbook.GetID()!=0)
        {
                s.out("离散数学");
                cout  <<"离散数学  已成功出库"  <<  endl;
        }
        else
                cout<<"没有找到name为离散数学的书"<<endl;
        cout  <<"现有库存书籍数量："<<s.GetCount()  <<  endl;

        cout  <<"查找图书  ID：3"  <<  endl;
        tmpbook=s.findbyID(3);
        if(tmpbook.GetID()!=0)
                cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl;
        else
                cout<<"没有找到ID为"<<3<<"的书"<<endl;

        cout  <<"查找图书  name：离散数学"  <<  endl;
        tmpbook=s.findbyName("离散数学");
        if(tmpbook.GetID()!=0)
                cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl;
        else
                cout<<"没有找到name为离散数学的书"<<endl;

        cout<<"输出所有库存图书的信息"<<endl;
        s.printList();
        cout<<"程序运行结束"<<endl;
        return  0;
}