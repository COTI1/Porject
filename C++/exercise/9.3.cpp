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

	friend ostream &operator <<(ostream &os, FTest &data);//友元函数  
	friend istream &operator >>(istream &is, FTest &data);
	friend class FTest2;
};



class FTest2 {
	//const int i = 3;  //c++11语法堂支持这种写法
	const int i ;
public:
	FTest2():i(3)//C++98
	{
		FTest ft(2, 3);
		cout << ft.m_a << endl;//FTest2是FTest的友元，
		//FTest2可以访问FTest的私有成员，FTest不能访问FTest2的私有成员
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
	os << data.m_a << ' '<<data.m_b;//m_a,m_b为私有，无法调用，需用到友元函数可以访问私有成员
	return os;
}

istream &operator >>(istream &is, FTest &data)//输入出流运算符重载，istream输入流
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

//内部类
class A {
public :
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
};//B可以访问A的私有成员，A不能访问B的私有成员

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
	A::B b;//内部类需是PUBLIC

	int i = A::SUN;//枚举
/*	
	
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
	*/
	
	//operator<<(cout,ft);
	//cout << ft << endl;//两种写法完全等价，cout多次调用函数，printf只调用一次，printf效率高
	
	return 0;
}