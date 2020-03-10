#include<iostream>
using namespace std;
//子类的函数与父类最好不要有同名函数，否则会被覆盖
//只要子类与父类的函数同名就会被隐藏，无论是否有参数
//基类定义了static静态成员，则整个继承体系里面只有一个这样的成员

class TestBase
{
public:
	int m_a;
	TestBase(int i) :
		m_a(i)
	{

	}

	void func(int i)
	{
		cout << "我是父类的函数"<<endl;
	}
};

//继承自TestBase
//父类的private，子类不可见，不能访问  protected可继承，可见。但不可访问

class Test :public TestBase   //public private 子类以那种形式继承父类
{
public:
	int m_a;//与父类有同名变量时，父类变量被隐藏
	Test(int a, int b) :
		TestBase(a) ,//直接调构造函数，父类只能在这
		m_a(b)
	{

	}

	void func()//只要子类与父类的函数同名就会被隐藏，无论是否有参数
	{
		cout << TestBase::m_a << endl;//声明作用域
		cout << "我是子类的函数"<<endl;
	}

};

int test1()
{
#if 1
	Test t(5, 6);

	t.func();
#else
	Test * pt = new Test(5, 6);
	TestBase * ptb = pt;

	cout << pt->m_a << endl;
	cout << ptb->m_a << endl;

	pt->func();
	ptb->func(1);
#endif
	return 0;
}








class TestBases
{
public:
	TestBases()
	{
		cout << "基类构造" << endl;
	}

	~TestBases()
	{
		cout << "基类析构" << endl;
	}
};

class Tests : public TestBases
{
public:
	Tests()
	{
		cout << "派生类构造" << endl;
	}

	void fun()
	{
		cout << "我是派生类" << endl;
	}

	~Tests()
	{
		cout << "派生类析构" << endl;
	}
};



int test2()
{
	Tests t;

	t.fun();//先调父类构造，再调子类构造
	        //先调子类析构，后调父类析构
	return 0;
}






class TBase1
{
public:
	static int m_s_i;
};

int TBase1::m_s_i = 10;//给静态变量赋初值

class TBase2 : public TBase1
{

};

class TBase3 : public TBase2
{

};

class TBase4 : public TBase3
{

};

int main()
{
	TBase4::m_s_i = 20;

	cout << TBase1::m_s_i;

	return 0;
}