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
        b1.SetName("C++  ���Գ������(��4��)");
        b1.SetAuthor("֣��");
        b1.SetIntroduction("����C++����������֪ʶ");
        b1.SetDate("201007");
        b1.SetPage(529);
        b2.SetID(2);
        b2.SetName("��ɢ��ѧ");
        b2.SetAuthor("��Т��");
        b2.SetIntroduction("���������߼���ν���߼��������ۡ�����ϵͳ��ͼ��");
        b2.SetDate("198209");
        b2.SetPage(305);
        b3.SetID(3);
        b3.SetName("c�������");
        b3.SetAuthor("̷��ǿ");
        b3.SetIntroduction("����C��������еĻ���֪ʶ��������ʽ���﷨��");
        b3.SetDate("201006");
        b3.SetPage(355);

        cout<<"��һ�������"<<endl;
        s.in(b1);
        cout<<"�ڶ��������"<<endl;
        s.in(b2);
        cout<<"�����������"<<endl;
        s.in(b3);
        cout  <<"���п���鼮������"<<s.GetCount()  <<  endl;
        cout  <<"���Ҳ�����ͼ�飺��ɢ��ѧ"  <<  endl;
        Book  tmpbook=s.findbyName("��ɢ��ѧ");
        if(tmpbook.GetID()!=0)
        {
                s.out("��ɢ��ѧ");
                cout  <<"��ɢ��ѧ  �ѳɹ�����"  <<  endl;
        }
        else
                cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl;
        cout  <<"���п���鼮������"<<s.GetCount()  <<  endl;

        cout  <<"����ͼ��  ID��3"  <<  endl;
        tmpbook=s.findbyID(3);
        if(tmpbook.GetID()!=0)
                cout<<"�ҵ�IDΪ"<<3<<"���飬������"<<tmpbook.GetName()<<endl;
        else
                cout<<"û���ҵ�IDΪ"<<3<<"����"<<endl;

        cout  <<"����ͼ��  name����ɢ��ѧ"  <<  endl;
        tmpbook=s.findbyName("��ɢ��ѧ");
        if(tmpbook.GetID()!=0)
                cout<<"�ҵ�nameΪ��ɢ��ѧ���飬ID��"<<tmpbook.GetID()<<endl;
        else
                cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl;

        cout<<"������п��ͼ�����Ϣ"<<endl;
        s.printList();
        cout<<"�������н���"<<endl;
        return  0;
}