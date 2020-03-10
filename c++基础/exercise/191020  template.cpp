#include<iostream>
using namespace std;

//特殊模板
//静态顺序表，不支持扩容,需传入一个大小
template<class T, size_t N = 10>
class Array
{
	T m_data[N];
public:
	Array()
	{
		cout << N;
	}
};


void test1()
{
	const int i = 100;
	Array<int, i> a;

}






//原模板
template<typename T>
void swapArgs(T & a, T &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//函数模板特化,模板的一小部分细化，跟原模板走，必须有原模板
template<>
void swapArgs<int>(int & a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//函数重载
void swapArgs(int & a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void test2()
{
	int a = 5;
	int b = 6;
	swapArgs(a, b);

	cout << a << ' ' << b << endl;
}








template<class T1, class T2>
class Test {
	T1 m_a;
	T2 m_b;
public:
	Test()
	{
		cout << "T1 T2" << endl;
	}
};

//类模板的特化
template<>
class Test <int, char> {
	int m_a;
	char m_b;
public:
	Test()
	{
		cout << "int char" << endl;
	}
};


//偏特化
template<class T1>
class Test <T1, double> {
	T1 m_a;
	double m_b;
public:
	Test()
	{
		cout << "T1 double" << endl;
	}
};


//特化成指针
template<class T1, class T2>
class Test <T1 *, T2 *> {
	T1 * m_a;
	T2 * m_b;
public:
	Test()
	{
		cout << "T1* T2*" << endl;
	}
};

template<class T1, class T2>
class Test <T1 &, T2 &> {
	T1 & m_a;
	T2 & m_b;
public:
	Test(T1 &a, T2 &b) :
		m_a(a),
		m_b(b)
	{
		cout << "T1& T2&" << endl;
		m_a = 8;//a会改变，m_a与a是同样的变量，只是起了一个别名
	}
};



void test3()
{
	Test<float, double> t1;
	Test<int, char> t2;
	Test<int *, float *> t3;
	int a = 0;
	char b = 0;
	Test<int &, char&> t4(a, b);

	cout << a << endl;
}







//类型萃取

//代表内置类型
class Truetype
{
public:
	static bool get()
	{
		return true;
	}
};
//代表自定义类型
class Falsetype
{
public:
	static bool get()
	{
		return false;
	}
};
//类模板
template <class T>
class TypeTraits
{
public:
	typedef Falsetype Jtype;
};
//类模板的实例化，所有内置类型都特化一下
template <>
class TypeTraits<int>
{
public:
	typedef Truetype Jtype;
};

template <>
class TypeTraits<float>
{
public:
	typedef Truetype Jtype;
};


void test4()
{
	cout << TypeTraits<int>::Jtype::get() << endl;
	cout << TypeTraits<float>::Jtype::get() << endl;//这两者特化了，其为内置类Truetype
	cout << TypeTraits<double>::Jtype::get() << endl;//没有被特化，为自定义类Falsetype
}






int main()
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}