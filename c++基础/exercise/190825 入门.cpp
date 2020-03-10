#include<iostream>
#include<stdlib.h>

using namespace std;//std域对自己可见，
//使用using namespace 命名空间名称引入

//命名空间内可以包含其他的（一个或多个）命名空间
namespace A {
	namespace n1 {
		int add(int a, int b)
		{
			std::cout << "A::N1";//若开头写了std，则输出可以不写
			return a + b;
		}

	}
	namespace n2 {
		int add(int a, int b)
		{
			std::cout << "A::N2";
			return a + b;
		}
	}
}

// 同一个工程中允许存在多个相同名称的命名空间 ，
//编译器后会合成同一个命名空间中
namespace n2 {
	int add(int a, int b)
	{
		std::cout << "n2 add";
		return a + b;
	}
}

namespace n2
{
	int sub(int a, int b)
	{
		cout << "n2 sub";
		return a - b;
	}
}

int add(int a, int b)
{
	cout << "add int";
	return a + b;
}
short add(short a, short b)
{
	cout << "add short";
	return a + b;
}

//一个命名空间就定义了一个新的作用域
void test1()
{
	cout << "Hello world!!!" << endl;
	cout << add(3, 5) << endl;
	cout << A::n2::add(2, 3) << endl;//即使n2域名相同，但其在不同的作用域里
	cout << n2::add(2, 3) << endl;//加命名空间名称及作用域限定符
	cout << n2::sub(5, 3) << endl;

}


//缺省参数不能在函数声明和定义中同时出现
void func(int a, int b, int c);
//全缺省参数 
void func(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

//半缺省参数必须按顺序赋值，即不能在调用时，写(func(10, , 30)
void TestFunc(int a, int b = 10, int c = 20)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

void test2()
{
	//必须按顺序赋值，即不能在调用时，写(func(10, , 30)
	TestFunc(1, 2);
	func();
	func(7);
	func(3, 4);
	func(2, 4, 6);
}


//函数重载
//允许在同一作用域中声明几个功能类似的同名函数
//但这些同名函数的 形参列表(参数个数 或 类型 或 顺序)必须不同
//参数不同，函数不同

void swapArgs(int * pa, int * pb)
{
	int tmp;

	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}


void swapArgs(float *pa, float *pb)
{
	float tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void test3()
{
	float a = 5.3, b = 6.7;
	int c = 4, d = 9;
	swapArgs(&a, &b);
	swapArgs(&c, &d);

	cout << a << " " << b << endl;
	cout << c << " " << d << endl;
}


int fmain()
{
	test3();

	return 0;
}
