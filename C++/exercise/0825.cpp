#include<iostream>
#include<stdlib.h>

using namespace std;//std����Լ��ɼ�

//�����ռ��ڿ��԰��������ģ�һ�������������ռ�
namespace test {
	namespace n1 {
		int add(int a, int b)
		{
			std::cout << "1\n";//����ͷд��std����������Բ�д
			return a + b;
		}

	}
	namespace n2 {
		int add(int a, int b)
		{
			std::cout << "2\n";
			return a + b;
		}
	}
}


namespace n2 {
	int add(int a, int b)
	{
		std::cout << "3\n";
		return a + b;
	}
}

void func(int a, int b, int c); //ȱʡ���������ں��������Ͷ�����ͬʱ����
void func(int a = 10, int b = 20, int c = 30)//ȫȱʡ����   ��ȱʡ�������밴˳��ֵ���������ڵ���ʱ��д(func(10, ,30)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

void swapArgs(int *pa, int *pb)//������ͬ��������ͬ
{
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pa = tmp;
}

void swapArgs(float *pa, float *pb)
{
	float tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
int main()
{
	//std::cout << test::n2::add(2, 3);
	//std::cout << n2::add(2, 3);
	//std::cout << "Hello world!!!" << std::endl;
	//func();
	//func(7);
	//func(3,4);
	//func(2,4,6);
	float a = 5.3, b = 6.7;
	int c = 4, d = 9;
	swapArgs(&a, &b);
	swapArgs(&c, &d);
	cout << a << " " << b << endl;
	cout << c << " " << d << endl;

	system("pause");
	return 0;
}



