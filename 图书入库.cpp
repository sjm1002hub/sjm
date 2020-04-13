#include  <iostream>
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

        unsigned int GetCount() { return m_Count; }
        void SetCount(unsigned int val) { m_Count = val; }
        Book* GetpBook() { return m_pBook; }
        void SetpBook(Book* val) { m_pBook = val; }
        Book findbyID(int ID);
        Book findbyName(string name);
        void in(Book &b);
        void out(string name);
        void printList();
    protected:

    private:
        unsigned int m_Count;
        Book* m_pBook;
};

Store::Store()
{
     m_Count=0;
    m_pBook=0;
    cout<<"Store default constructor called!"<<endl;
}
Store::Store(int n)
{
      m_Count=n;
    m_pBook=new Book[n] ;
    cout<<"Store constructor with (int n) called!"<<endl;
}

Store::~Store()
{
     m_Count=0;
    if(m_pBook!=0)
    {delete[] m_pBook;
    cout<<"Store destructor called!"<<endl;}
}

Store::Store(const Store& other)
{
     m_Count=other.m_Count;
    m_pBook=new Book[m_Count];
    for(unsigned int i=0;i<m_Count;i++)
    {
        m_pBook[i].SetID(other.m_pBook[i].GetID());
        m_pBook[i].SetName(other.m_pBook[i].GetName());
        m_pBook[i].SetAuthor(other.m_pBook[i].GetAuthor());
        m_pBook[i].SetDate(other.m_pBook[i].GetDate());
        m_pBook[i].SetIntroduction(other.m_pBook[i].GetIntroduction());
        m_pBook[i].SetPage(other.m_pBook[i].GetPage());

    }
    cout<<"Store copy constructor called!"<<endl;
}
Book Store::findbyName(string name)
{  Book a;unsigned int i;
  for(i=0;i<m_Count;i++)
 if(m_pBook[i].GetName()==name)

 { a=m_pBook[i]; break;}
 if(i==m_Count) a.SetID(0);



return a;
}
Book Store::findbyID(int ID)
{  Book q;unsigned int i;
  for( i=0;i<m_Count;i++)
 if(m_pBook[i].GetID()==ID)

 {  q=m_pBook[i];  break;}

if(i==m_Count)  q.SetID(0);
return q;
}
void Store::in(Book &b)
{
	m_Count++;
  Book *p=new Book[m_Count];
for(unsigned int i=0;i<m_Count-1;i++)
        p[i]=m_pBook[i];
          p[m_Count-1]=b;
        
        delete[] m_pBook;
       m_pBook=p;
}
void Store::out(string name)
{ unsigned int i,j;
for( i=0;i<m_Count;i++)
 if(m_pBook[i].GetName()==name) break;
Book *p=new Book[m_Count];
for(j=0;j<i;j++)
  p[j]=m_pBook[j];
for(;j<m_Count-1;j++)
  p[j]=m_pBook[j+1];
delete[] m_pBook;
m_pBook=p;
m_Count--;
}
void Store::printList()
{
 cout<<"There are totally "<<m_Count<<" Books:"<<endl;
for(unsigned int i=0;i<m_Count;i++)
{cout<<"ID="<<m_pBook[i].GetID()<<"; ";
cout<<"Name:"<<m_pBook[i].GetName()<<"; ";
cout<<"Author:"<<m_pBook[i].GetAuthor()<<"; ";
cout<<"Page:"<<m_pBook[i].GetPage()<<"; "<<endl;
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