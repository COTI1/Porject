#include<iostream>
using namespace std;


class Test {
	int m_a;
public:
	Test(int a = 0) :
		m_a(a)
	{

	}
	//需要返回左值时传引用

	//前置++
	Test operator ++ ()
	{
		m_a++;
		return *this;
	}
	//后置++
	Test operator ++ (int)
	{
		Test tmp = *this;
		m_a++;
		return tmp;
	}
	friend ostream &operator <<(ostream &os, Test & d);//友元函数
};


ostream &operator <<(ostream &os, Test & d)
{
	os << d.m_a << endl;
	return os;
}




int main()
{

	Test t(7);
	cout << t;//7
	cout << t.operator++(0);//7
	cout << t.operator++();//8
	cout << t.operator++(1);//8

	return 0;
}