#include<iostream>
#include<stdlib.h>

using namespace std;//std����Լ��ɼ���
//ʹ��using namespace �����ռ���������

//�����ռ��ڿ��԰��������ģ�һ�������������ռ�
namespace A {
	namespace n1 {
		int add(int a, int b)
		{
			std::cout << "A::N1";//����ͷд��std����������Բ�д
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

// ͬһ��������������ڶ����ͬ���Ƶ������ռ� ��
//���������ϳ�ͬһ�������ռ���
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

//һ�������ռ�Ͷ�����һ���µ�������
void test1()
{
	cout << "Hello world!!!" << endl;
	cout << add(3, 5) << endl;
	cout << A::n2::add(2, 3) << endl;//��ʹn2������ͬ�������ڲ�ͬ����������
	cout << n2::add(2, 3) << endl;//�������ռ����Ƽ��������޶���
	cout << n2::sub(5, 3) << endl;

}


//ȱʡ���������ں��������Ͷ�����ͬʱ����
void func(int a, int b, int c);
//ȫȱʡ���� 
void func(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

//��ȱʡ�������밴˳��ֵ���������ڵ���ʱ��д(func(10, , 30)
void TestFunc(int a, int b = 10, int c = 20)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

void test2()
{
	//���밴˳��ֵ���������ڵ���ʱ��д(func(10, , 30)
	TestFunc(1, 2);
	func();
	func(7);
	func(3, 4);
	func(2, 4, 6);
}


//��������
//������ͬһ�����������������������Ƶ�ͬ������
//����Щͬ�������� �β��б�(�������� �� ���� �� ˳��)���벻ͬ
//������ͬ��������ͬ

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
