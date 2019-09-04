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

int test1(int &a)
{
	return a;
}
int &test3(int &a)
{
	return a;
}
int test2(int &a)
{
	return a;
}

struct A { int a[10000]; };


void TestFunc1(A a) {}

void TestFunc2(A& a) {}
int main()
{
	/* auto可以自己判断类型
	int i = 0;
	auto j = i;
	auto q= &i;
	cout << typeid(q).name() << endl;
	*/
	
	
	//TestFunc1;
	//TestFunc2;
	
	/*
	int a = 3;
	cout << test1(a) << endl;
	cout << test2(a) << endl;
	cout << (test3(a)=4) << endl;//返回引用相当于返回引用本身
	//相当于C中*fun3(&a)=5  
	*/
	
	
	
	/*
	const int a = 10;
	const int &ra = a;
	double b= 1.23;
	double &rb = b;
	const double &reb = b;
    */

	
	
	/*  引用
	int ming = 5;
	int &xiaoming = ming;
	cout << &ming << endl;
	cout << &xiaoming << endl;
	cout << xiaoming << endl;
	*/
	
	
	/*  C语言不执行
	int a = 3, b = 4.6, c = 5.5;
	func(a);
	func(b, c);
	std::cout << a << " " << b << " " << c << std::endl;
	*/
	system("pause");
	
	return 0;

}