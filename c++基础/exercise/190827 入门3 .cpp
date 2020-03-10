#include<iostream>
#include<cstdlib>
#include <vector>
#include <typeinfo>//���Կ�������
using namespace std;
#include <stdio.h>


//funcpointer

extern "C" {
	int add(int a, int b)
	{
		return a + b;
	}
}

int main()
{
	int(*pfunc)(int, int) = add;

	cout << pfunc(2, 3);
	return 0;
}







void test3()
{
	int arr[] = { 2,5,1,3,4 };

	//��һ�����Ƿ�Χ�����ڵ����ı�����
	//�ڶ��������ʾ�������ķ�Χ��

	for (int i : arr)//ȫ������
	{
		cout << i << " ";
	}

	cout << endl;



	for (auto &i : arr)//����
	{
		i *= 2;
	}

	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;


	//forѭ�������ķ�Χ������ȷ���� 
	//����������ԣ����������е�һ��Ԫ�غͺ�һ��Ԫ�صķ�Χ��
	//��������ԣ�Ӧ���ṩbegin��end�� ������begin��end����forѭ�������ķ�Χ
	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}







void func(int a)
{
	cout << "1" << endl;
}


void func(int * pa)
{
	cout << "2" << endl;
}

void test2()
{
	//int * pa = nullptr;
	//nullptr_t a = nullptr;


	cout << typeid(nullptr).name() << endl;
	func(0);//���Ϊ1    ������Ĭ������� ���俴����һ�����γ�����
			 //���Ҫ���䰴��ָ�뷽ʽ��ʹ�ã�����������ǿת(void *)
	func(NULL);//1   NULL���ܱ�����Ϊ���泣��0��
					 //���߱�����Ϊ������ָ��(void*)�ĳ�����
	func(nullptr);//2   nullptr����һ��ָ���ֵ����
	func((int *)NULL);//2

}
