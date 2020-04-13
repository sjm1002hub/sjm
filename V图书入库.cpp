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