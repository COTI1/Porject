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
	c.changeA(5);//��Ա������ᴫ��һ��������ʽ��THISָ�봫��
	c.printA();
	ct* pc = nullptr;
	/*
    �൱��C�еĵ���c.printA(&c);
	ʵ�ֺ���Ϊ
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