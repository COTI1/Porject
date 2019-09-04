#include<iostream>
#include<cstdlib>
using namespace std;

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

int TestSt::m_s_i = 0;





class Testop
{
public:
	int m_a;
	int m_b;

	Testop():
		m_a(0),m_b(0)
	{
	}
	Testop(int a,int b) :
		m_a(a), m_b(b)
	{
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


class Test {
public:
	int a = 5;
	const int i=3;//C++11可以在这里直接赋值
	int &ri;
	Test2 t2;
	
	//Test的构造函数
	Test(int &a):i(3),ri(a),t2(a)//t2(Test2(a))的省略     //写在冒号后面为初始化，CONST狭义初始化
	{
		//这里只是赋值，广义初始化
	}
};



int main()
{   
	//可以统计创建的对象，相当于全局变量
	//static 共用同一片空间
	TestSt t1;
	cout << t1.m_s_i << endl;
	TestSt t2;
	cout << t1.m_s_i << endl;
	cout << t2.m_s_i << endl;
	TestSt t3;
	cout << t1.m_s_i << endl;
	cout << t2.m_s_i << endl;
	cout << t3.m_s_i << endl;
	
	cout << TestSt::m_s_i << endl;
	cout <<sizeof( TestSt)<< endl;
	
	
	
	/*
	Testop a(3, 5);
	Testop b(2, 7);
	
	Testop c;
	c = a + b;
	cout << c.m_a<< ' '<<c.m_b<<endl;
	
	
	
	
	int i = 8;
	Test a(i);
	Test b = a;
	cout << b.ri << endl;
	



	int c = 2;
	Test a(c);
	cout << a.t2.b << endl;
	cout << a.i << endl; //CONST可以直接应用
	cout << a.a << endl;
	*/
	system("pause");
	return 0;
}