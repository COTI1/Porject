#include<iostream>
#include <fstream>
using namespace std;


class ct {
	int a;   //˽�г�Ա����
public:
	double b = 2;
	char c;
	void changeA(int i)
	{
		a = i;//this->a=i;
	}
	void printA()
	{
		printf("%d\n", a);
	}
	void test()
	{
		printf("test");
	}
protected://����
	void printB();
};



void ct::printB()
{
	printf("%.2lf\n", b);
}

void test0828()
{
	ct c;
	ct d;
	c.changeA(5);//��Ա������ᴫ��һ��������ʽ��thisָ�봫��
	c.printA();
	ct* pc = nullptr;
	ct* pd = &c;
	/*
	�൱��C�еĵ���c.printA(&c);
	ʵ�ֺ���Ϊ
	void printA(ct* this)
	{
		cout << this->a << endl;
	}
   */
	d.changeA(6);
	d.printA();

	d.b = 5;
	cout << d.b << endl;


	cout << (pd->b = 6) << endl;//��������ֵ
	cout << c.b << endl;

	pc->test();//ָ�����
	cout << sizeof(ct) << endl;//���Ϊ24

}






class TestSt
{
public:
	static int m_s_i;
	TestSt()
	{
		m_s_i++;
	}

	static void testst(TestSt & a) //��̬�������Է��ʾ�̬��Ա���������ܷ�����ͨ��Ա����
	{
		m_s_i = 4;
	}
};

int TestSt::m_s_i = 0;//��̬���ݳ�Ա����class���ʼ�������Ǿ�̬���ݳ�Ա�����������ʼ��

void modify083002()
{
	
//����ͳ�ƴ����Ķ����൱��ȫ�ֱ���
//static ����ͬһƬ�ռ�
	 TestSt t1;
	 cout << t1.m_s_i << endl;//1
	TestSt t2;
	cout << t1.m_s_i << "  ";//2
	cout << t2.m_s_i << endl;//2
	TestSt t3;
	cout << t1.m_s_i << "  ";//3
	cout << t2.m_s_i << "  ";//3
	cout << t3.m_s_i << endl;//3

	cout << TestSt::m_s_i << endl;//3
	cout << sizeof(TestSt) << endl;//����ռһ���ڴ�


}


class Testop
{
public:
	int m_a;
	int m_b;

	Testop() :
		m_a(0), m_b(0)
	{
	}
	Testop(int a, int b) :
		m_a(a), m_b(b)
	{
	}
	void test1(int a, int b)
	{
		test2(2, 4);
	}

	void test2(int a, int b) const
	{
		//test1(2, 4);
	}
	Testop operator+(const Testop &s)  const//this���䣬��m_a,m_b����
	{
		Testop res;
		res.m_a = m_a + s.m_a;
		res.m_b = m_b + s.m_b;
		return res;
	}
	Testop &operator=(const Testop &s)
	{
		m_a = s.m_a;
		m_b = s.m_b;

		return *this;
	}
};

class Test2 {
public:
	int b;

	//Test2�Ĺ��캯��
	Test2(int i)
	{

		b = i;
	}
};

void modify083001()
{
	Testop a(3, 5);
	Testop b(2, 7);
	Testop c;
	c = a + b;
	cout << c.m_a << ' ' << c.m_b << endl;
}

class Test {
public:
	int a = 5;
	const int i = 3;//C++11����������ֱ�Ӹ�ֵ
	int &ri;
	Test2 t2;

	//Test�Ĺ��캯��
	Test(int &a) :i(3), ri(a), t2(a)//t2(Test2(a))��ʡ��     //д��ð�ź���Ϊ��ʼ����CONST�����ʼ��
	{
		//����ֻ�Ǹ�ֵ�������ʼ��
	}
};


void modify083003()
{

	int i = 8;
	Test d(i);
	Test e = d;
	cout << e.ri << endl;//8

	int f = 2;
	Test g(f);
	cout << g.t2.b << endl;//2
	cout << g.i << endl; //CONST����ֱ��Ӧ��
	cout << g.a << endl;
}

int test0830()
{
	modify083001();
	modify083002();
	modify083003();

	return 0;
}












class FTest {
	int m_a;
	int m_b;
public:
	FTest() :
		m_a(0),
		m_b(0)
	{

	}
	FTest(int a, int b) :
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
	const int i;
public:
	FTest2() :i(3)//C++98
	{
		FTest ft(2, 3);
		cout << ft.m_a << endl;//FTest2��FTest����Ԫ��
		//FTest2���Է���FTest��˽�г�Ա��FTest���ܷ���FTest2��˽�г�Ա
	}
	void input()
	{

	}

	void output() const
	{

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
	os << data.m_a << ' ' << data.m_b;//m_a,m_bΪ˽�У��޷����ã����õ���Ԫ�������Է���˽�г�Ա
	return os;
}

istream &operator >>(istream &is, FTest &data)//���������������أ�istream������
{
	is >> data.m_a >> data.m_b;
	return is;
}

void modify090301()
{
	FTest ft;
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
public:
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
	public:
		int a;
		int b;

		B() :
			a(0),
			b(8)
		{

			s_a = FRI;
		}
	}a;
	int b;
public:
	A() :
		a(),
		b(5)
	{
	}
};//B���Է���A��˽�г�Ա��A���ܷ���B��˽�г�Ա

int A::s_a = 3;

void modify090302()
{
	int a = 4;
	int s = 3;
	{
		int a = 5;   //�з�Χ����
		cout << a << endl;//���Ϊ5
		cout << s << endl;
	}
	cout << a << endl;//���Ϊ4


	FTest ft;
	A::B g;//�ڲ�������PUBLIC
	cout << g.b << endl;//���Ϊ8
	cout << g.a << endl;

	A e;
	cout << e.s_a << endl;//���Ϊ5
	cout << e.b << endl;//���Ϊ5
	int i = A::SUN;//ö��
	cout << i;

	//operator<<(cout,ft);
	//cout << ft << endl;//����д����ȫ�ȼۣ�cout��ε��ú�����printfֻ����һ�Σ�printfЧ�ʸ�

}

void test0903()
{
	modify090301();
	modify090302();
}




class test
{
	int m_a;
	int m_b;
	int * m_pt;
public:
	test() : //������������ͬΪ���캯��
		m_a(0),
		m_b(0)
	{
		m_pt = new int;
	}

	test(int a, int b) :
		m_a(a),
		m_b(b)
	{
		m_pt = new int;
	}
	~test() //��������
	{
		delete m_pt;
	}
	void printTest()
	{
		cout << m_a << ' ' << m_b << endl;
	}
};
int test0905()
{
	/*
	const int i = 2;
	printf("%p\n", &i);
	*((int *)&i) = 4;
	printf("%d", i);
   */
	test a;
	//test *pa = (test*)malloc(sizeof(test));   free(pa); //C

	test *pa = new test(3, 6);//��ָ���ָ�����ռ�
	pa->printTest();


	delete pa;
	return 0;
}


int main()
{
	//test0828();
	//test0830();
	//test0903();
	test0905();

	return 0;
}