#include<iostream>
#include <fstream>
using namespace std;


class ct {
	int a;   //私有成员函数
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
protected://保护
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
	c.changeA(5);//成员函数里会传入一个对象，隐式以this指针传入
	c.printA();
	ct* pc = nullptr;
	ct* pd = &c;
	/*
	相当于C中的调用c.printA(&c);
	实现函数为
	void printA(ct* this)
	{
		cout << this->a << endl;
	}
   */
	d.changeA(6);
	d.printA();

	d.b = 5;
	cout << d.b << endl;


	cout << (pd->b = 6) << endl;//给变量赋值
	cout << c.b << endl;

	pc->test();//指针调用
	cout << sizeof(ct) << endl;//结果为24

}






class TestSt
{
public:
	static int m_s_i;
	TestSt()
	{
		m_s_i++;
	}

	static void testst(TestSt & a) //静态函数可以访问静态成员变量，不能访问普通成员变量
	{
		m_s_i = 4;
	}
};

int TestSt::m_s_i = 0;//静态数据成员需在class外初始化，而非静态数据成员不能在外面初始化

void modify083002()
{
	
//可以统计创建的对象，相当于全局变量
//static 共用同一片空间
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
	cout << sizeof(TestSt) << endl;//函数占一个内存


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
	Testop operator+(const Testop &s)  const//this不变，即m_a,m_b不变
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

	//Test2的构造函数
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
	const int i = 3;//C++11可以在这里直接赋值
	int &ri;
	Test2 t2;

	//Test的构造函数
	Test(int &a) :i(3), ri(a), t2(a)//t2(Test2(a))的省略     //写在冒号后面为初始化，CONST狭义初始化
	{
		//这里只是赋值，广义初始化
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
	cout << g.i << endl; //CONST可以直接应用
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

	friend ostream &operator <<(ostream &os, FTest &data);//友元函数  
	friend istream &operator >>(istream &is, FTest &data);
	friend class FTest2;
};

class FTest2 {
	//const int i = 3;  //c++11语法堂支持这种写法
	const int i;
public:
	FTest2() :i(3)//C++98
	{
		FTest ft(2, 3);
		cout << ft.m_a << endl;//FTest2是FTest的友元，
		//FTest2可以访问FTest的私有成员，FTest不能访问FTest2的私有成员
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

//除了输入，输出函数，尽量不用友元函数，可以在类中写一个访问函数
ostream &operator <<(ostream &os, FTest &data)//输出流运算符重载，operator重载关键字,ostream输出流
{
	os << data.m_a << ' ' << data.m_b;//m_a,m_b为私有，无法调用，需用到友元函数可以访问私有成员
	return os;
}

istream &operator >>(istream &is, FTest &data)//输入出流运算符重载，istream输入流
{
	is >> data.m_a >> data.m_b;
	return is;
}

void modify090301()
{
	FTest ft;
	//输出文件内容
	ifstream is("1.txt");
	is >> ft;
	cout << ft << endl;
	is.close();



	//向文件写入
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




//内部类
class A {
public:
	enum {//批量定义常量的方式
		SUN,
		MON,
		TUE,
		WED,
		TUR,
		FRI,
		SAT
	}e;//e为变量，只能取这7个
	static int s_a;//静态成员变量类在它在

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
};//B可以访问A的私有成员，A不能访问B的私有成员

int A::s_a = 3;

void modify090302()
{
	int a = 4;
	int s = 3;
	{
		int a = 5;   //有范围限制
		cout << a << endl;//结果为5
		cout << s << endl;
	}
	cout << a << endl;//结果为4


	FTest ft;
	A::B g;//内部类需是PUBLIC
	cout << g.b << endl;//结果为8
	cout << g.a << endl;

	A e;
	cout << e.s_a << endl;//结果为5
	cout << e.b << endl;//结果为5
	int i = A::SUN;//枚举
	cout << i;

	//operator<<(cout,ft);
	//cout << ft << endl;//两种写法完全等价，cout多次调用函数，printf只调用一次，printf效率高

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
	test() : //与类名名字相同为构造函数
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
	~test() //析构函数
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

	test *pa = new test(3, 6);//给指针的指向分配空间
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