#include<iostream>
#include<stdlib.h>
using namespace std;


extern "C"    //以C语言运行，函数报错
{
	int func(int a)
	{
		return a;
	}
}


float func(float a, float b)
{
	return a;
}

int test1()
{

	/*  C语言不执行*/
	int a = 3, f = 4, d = 6;
	float b = 4.6, c = 5.5;
	float e = 4.3;
	func(a);
	func(e);   //调用时输出float类型的数字
	func(b, c);
	func(d, f);//调用时输出int类型的数字
	cout << a << " " << e << " " << b;
	cout << " " << c << " " << d << " " << f;

	return 0;

}


//引用
//1. 引用在定义时必须初始化 
//2. 一个变量可以有多个引用,一个引用只能引用一个实体
void test2()
{
	/*  带引用为地址，不带为值*/
	const int a = 10;
	const int &ra = a;//常引用

	double b = 1.23;
	double &rb = b;
	const double &reb = b;
	cout << a << " " << ra << " " << &ra << endl;
	cout << b << " " << rb << " " << &rb << endl;
	cout << reb << " " << &reb << endl;


	/*  引用*/
	int ming = 5;
	int &xiaoming = ming;
	cout << &ming << endl;//地址
	cout << &xiaoming << endl;//地址
	cout << xiaoming << endl;//值

	int xiao = ming;
	cout << &xiao << endl;//地址
	cout << xiao << endl;//值

}


int t1(int a)
{
	return a;
}
//引用做参数
int t2(int &a)
{
	return a;
}

//引用做返回值
//返回引用相当于返回引用本身
//如果函数返回时，离开函数作用域后，其栈上空间已经还给系统，因此不能用栈上的空间作为引 用类型返回。
//如果以引用类型返回，返回值的生命周期必须不受函数的限制(即比函数生命周期长)
inline int &t3(int &a)
{
	return a;
}

//内敛函数，没有函数压栈的开销， 内联函数提升程序运行的效率。
inline int *t4(int * pa)
{
	return pa;
}

void test3()
{
	int a = 3;
	cout << t1(a) << endl;
	cout << t2(a) << endl;
	cout << (t3(a) = 4) << endl;//4
	cout << (*t4(&a) = 5);
}




struct A { int a[10000]; };
//以值作为参数或者返回值类型
//传递的是实参或者返回变量的一份临时的拷贝
//所以传引用较快
void TestFunc1(A a) {}

void TestFunc2(A &a) {}

void test4()
{
	A a;
	for (int i = 0; i < 100000; i++)
	{
		TestFunc2(a);
	}
	TestFunc1;
	TestFunc2;


}




/* auto可以自己判断类型*/
void test5()
{
	int i = 0;
	auto j = i;
	auto q = &i;
	cout << typeid(q).name() << endl;

}

int main()
{
	test5();
	return 0;
}