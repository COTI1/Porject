
#include <stdio.h>



struct A1 {
	int a;
	double b;
};

struct A2 {

};



struct A3 {   //struct���Լ���������
	int a;
	double b;
	char c;
	void printA() //��Ա����    �п���ֱ��ʹ���Լ��ĳ�Ա����    ��ռ�ռ�   ֻ�����ֶ��˸�����
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