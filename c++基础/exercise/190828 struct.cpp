#include<iostream>
#include <cstdio>
#include<cstdlib>
using namespace std;

//struct看成一个作用域，A1为域名
struct A1 {
	int a;
	double b;
};

struct A2 {
	//保护空间，占一字节。c不允许
};



struct A3 {
	int a;
	double b;
	char c;
	void printA() //成员函数中可以直接使用自己的成员变量，无须传入
	{
		printf("%d\n", a);
	}
	void printB();//成员函数不占结构体空间，占公共区间
};



void A3::printB()
{
	printf("%.2lf\n", b);
}

/**/
namespace n1
{
	int a;

	void printA()
	{
		printf("%d\n", a);
	}
}


int main()
{
	printf("%d %d %d\n", sizeof(A1), sizeof(A2), sizeof(A3));
	A3 test;
	printf("%p %p %p\n%p\n", &test.a, &test.b, &test.c, &test);
	test.a = 5;
	test.printA();
	test.b = 3.14;
	test.printB();

    n1::printA();
	return 0;
}