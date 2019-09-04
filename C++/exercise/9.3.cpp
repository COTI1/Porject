#include<iostream>
#include<fstream>
using namespace std;

class FTest {
	int m_a;
	int m_b;
public:
	FTest() :
		m_a(0),
		m_b(0)
	{

	}
	FTest(int a,int b) :
		m_a(a),
		m_b(b)
	{

	}
	void setNum(int a, int b);

	friend ostream &operator <<(ostream &os, FTest &data);//��Ԫ����  
	friend istream &operator >>(istream &is, FTest &data);
	friend class FTest2;
};



class FTest2 {
	//const int i = 3;  //c++11�﷨��֧������д��
	const int i ;
public:
	FTest2():i(3)//C++98
	{
		FTest ft(2, 3);
		cout << ft.m_a << endl;//FTest2��FTest����Ԫ��
		//FTest2���Է���FTest��˽�г�Ա��FTest���ܷ���FTest2��˽�г�Ա
	}
};


void FTest::setNum(int a, int b)
{
	m_a = a;
	m_b = b;
}

//�������룬�������������������Ԫ����������������дһ�����ʺ���
ostream &operator <<(ostream &os, FTest &data)//�������������أ�operator���عؼ���,ostream�����
{
	os << data.m_a << ' '<<data.m_b;//m_a,m_bΪ˽�У��޷����ã����õ���Ԫ�������Է���˽�г�Ա
	return os;
}

istream &operator >>(istream &is, FTest &data)//���������������أ�istream������
{
	is >> data.m_a >> data.m_b;
	return is;
}
/*
struct A {
	struct	B
	{
		int a;
		int b;
	}a;
	int b;
};

*/

//�ڲ���
class A {
public :
	enum {//�������峣���ķ�ʽ
		SUN,
		MON,
		TUE,
		WED,
		TUR,
		FRI,
		SAT
	}e;//eΪ������ֻ��ȡ��7��
	static int s_a;//��̬��Ա������������

	class	B
	{
		int a;
		int b;
	public:
		B() :
			a(0),
			b(0)
		{
			
			s_a = FRI;
		}
	}a;
	int b;
public:
	A() :
		a(),
		b(0)
	{
	}
};//B���Է���A��˽�г�Ա��A���ܷ���B��˽�г�Ա

int A::s_a = 3;

int main()
{
	int a = 4;
	int s = 3;
	{
		int a = 5;
		cout << a << endl;
		cout << s << endl;
	}
	




    FTest ft;
	A::B b;//�ڲ�������PUBLIC

	int i = A::SUN;//ö��
/*	
	
	//����ļ�����
	ifstream is("1.txt");
	is >> ft;
	cout << ft << endl;
	is.close();
	
	
	
	//���ļ�д��
	ofstream os("1.txt");
	cin >> ft;
	os << ft << endl;
	os.close();
	*/
	
	//operator<<(cout,ft);
	//cout << ft << endl;//����д����ȫ�ȼۣ�cout��ε��ú�����printfֻ����һ�Σ�printfЧ�ʸ�
	
	return 0;
}