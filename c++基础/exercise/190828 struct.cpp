#include<iostream>
#include <cstdio>
#include<cstdlib>
using namespace std;

//struct����һ��������A1Ϊ����
struct A1 {
	int a;
	double b;
};

struct A2 {
	//�����ռ䣬ռһ�ֽڡ�c������
};



struct A3 {
	int a;
	double b;
	char c;
	void printA() //��Ա�����п���ֱ��ʹ���Լ��ĳ�Ա���������봫��
	{
		printf("%d\n", a);
	}
	void printB();//��Ա������ռ�ṹ��ռ䣬ռ��������
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