#include<iostream>
#include<cstdlib>
#include <vector>
#include <typeinfo>//���Կ�������
using namespace std;



void func(int a)

{

	cout << "1" << endl;

}



void func(int * pa)

{

	cout << "2" << endl;

}



int main0()
{
	//int * pa = nullptr;
	//nullptr_t a = nullptr;
	
	
	cout << typeid(nullptr).name() << endl;
	func(0);
	func(NULL);
	func((int *)NULL);
	return 0;

}

int main()
{
	int arr[] = { 2,5,1,3,4 };


	for (int i:arr)//ȫ������
	{
		cout << i << endl;
	}

	for (auto &i : arr)//����
	{
		i*=2;
	}

	for (auto i : arr)
	{
		cout << i << endl;
	}
	
	vector<int> v;



	v.push_back(1);

	v.push_back(2);

	v.push_back(3);

	v.push_back(4);

	v.push_back(5);



	for (auto i : v)

	{

		cout << i << endl;

	}
	return 0;
}