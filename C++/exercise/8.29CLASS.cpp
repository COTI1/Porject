#include<iostream>
using namespace std;


class ct { 
    int a;
public:	
	double b;
	char c;
	void changeA(int i)
	{
		a = i;//this->a=i;
	}
	void printA() 
	{
		printf("%d\n", a);
	}
	void test()
	{

	}
protected:
	void printB();
};


void ct::printB()
{
	printf("%.2lf\n", b);
}

int main()
{
	ct c;
	ct d;
	c.changeA(5);//成员函数里会传入一个对象，隐式以THIS指针传入
	c.printA();
	ct* pc = nullptr;
	/*
    相当于C中的调用c.printA(&c);
	实现函数为
	void printA(ct* this)
	{
		cout << this->a << endl;
	}
   */
	d.changeA(6);
	d.printA();
	pc->test();
	//cout << sizeof(ct) << endl;


	system("pause");
	return 0;
}