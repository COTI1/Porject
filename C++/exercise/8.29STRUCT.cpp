
#include <stdio.h>



struct A1 {
	int a;
	double b;
};

struct A2 {

};



struct A3 {   //struct是自己的作用域
	int a;
	double b;
	char c;
	void printA() //成员函数    中可以直接使用自己的成员变量    不占空间   只是名字多了个域名
	{
		printf("%d\n", a);
	}
	void printB();
};



void A3::printB()
{
	printf("%.2lf\n", b);
}


int main0()
{
	printf("%d %d %d\n", sizeof(A1), sizeof(A2), sizeof(A3));
	//printf("%p %p %p\n%p\n", &test.a, &test.b, &test.c, &test);
	A3 test;
	test.a = 5;
	test.printA();
	test.b = 3.14;
	test.printB();
	return 0;
}