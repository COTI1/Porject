#include<iostream>
#include<cstdlib>
#include <vector>
#include <typeinfo>//可以看到类型
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

	//第一部分是范围内用于迭代的变量，
	//第二部分则表示被迭代的范围。

	for (int i : arr)//全部遍历
	{
		cout << i << " ";
	}

	cout << endl;



	for (auto &i : arr)//引用
	{
		i *= 2;
	}

	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;


	//for循环迭代的范围必须是确定的 
	//对于数组而言，就是数组中第一个元素和后一个元素的范围；
	//对于类而言，应该提供begin和end的 方法，begin和end就是for循环迭代的范围
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
	func(0);//结果为1    编译器默认情况下 将其看成是一个整形常量，
			 //如果要将其按照指针方式来使用，必须对其进行强转(void *)
	func(NULL);//1   NULL可能被定义为字面常量0，
					 //或者被定义为无类型指针(void*)的常量。
	func(nullptr);//2   nullptr代表一个指针空值常量
	func((int *)NULL);//2

}
