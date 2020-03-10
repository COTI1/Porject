#include<iostream>
#include<stdlib.h>
using namespace std;


extern "C"    //��C�������У���������
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

	/*  C���Բ�ִ��*/
	int a = 3, f = 4, d = 6;
	float b = 4.6, c = 5.5;
	float e = 4.3;
	func(a);
	func(e);   //����ʱ���float���͵�����
	func(b, c);
	func(d, f);//����ʱ���int���͵�����
	cout << a << " " << e << " " << b;
	cout << " " << c << " " << d << " " << f;

	return 0;

}


//����
//1. �����ڶ���ʱ�����ʼ�� 
//2. һ�����������ж������,һ������ֻ������һ��ʵ��
void test2()
{
	/*  ������Ϊ��ַ������Ϊֵ*/
	const int a = 10;
	const int &ra = a;//������

	double b = 1.23;
	double &rb = b;
	const double &reb = b;
	cout << a << " " << ra << " " << &ra << endl;
	cout << b << " " << rb << " " << &rb << endl;
	cout << reb << " " << &reb << endl;


	/*  ����*/
	int ming = 5;
	int &xiaoming = ming;
	cout << &ming << endl;//��ַ
	cout << &xiaoming << endl;//��ַ
	cout << xiaoming << endl;//ֵ

	int xiao = ming;
	cout << &xiao << endl;//��ַ
	cout << xiao << endl;//ֵ

}


int t1(int a)
{
	return a;
}
//����������
int t2(int &a)
{
	return a;
}

//����������ֵ
//���������൱�ڷ������ñ���
//�����������ʱ���뿪�������������ջ�Ͽռ��Ѿ�����ϵͳ����˲�����ջ�ϵĿռ���Ϊ�� �����ͷ��ء�
//������������ͷ��أ�����ֵ���������ڱ��벻�ܺ���������(���Ⱥ����������ڳ�)
inline int &t3(int &a)
{
	return a;
}

//����������û�к���ѹջ�Ŀ����� �������������������е�Ч�ʡ�
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
//��ֵ��Ϊ�������߷���ֵ����
//���ݵ���ʵ�λ��߷��ر�����һ����ʱ�Ŀ���
//���Դ����ýϿ�
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




/* auto�����Լ��ж�����*/
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