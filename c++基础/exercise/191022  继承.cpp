#include<iostream>
using namespace std;
//����ĺ����븸����ò�Ҫ��ͬ������������ᱻ����
//ֻҪ�����븸��ĺ���ͬ���ͻᱻ���أ������Ƿ��в���
//���ඨ����static��̬��Ա���������̳���ϵ����ֻ��һ�������ĳ�Ա

class TestBase
{
public:
	int m_a;
	TestBase(int i) :
		m_a(i)
	{

	}

	void func(int i)
	{
		cout << "���Ǹ���ĺ���"<<endl;
	}
};

//�̳���TestBase
//�����private�����಻�ɼ������ܷ���  protected�ɼ̳У��ɼ��������ɷ���

class Test :public TestBase   //public private ������������ʽ�̳и���
{
public:
	int m_a;//�븸����ͬ������ʱ���������������
	Test(int a, int b) :
		TestBase(a) ,//ֱ�ӵ����캯��������ֻ������
		m_a(b)
	{

	}

	void func()//ֻҪ�����븸��ĺ���ͬ���ͻᱻ���أ������Ƿ��в���
	{
		cout << TestBase::m_a << endl;//����������
		cout << "��������ĺ���"<<endl;
	}

};

int test1()
{
#if 1
	Test t(5, 6);

	t.func();
#else
	Test * pt = new Test(5, 6);
	TestBase * ptb = pt;

	cout << pt->m_a << endl;
	cout << ptb->m_a << endl;

	pt->func();
	ptb->func(1);
#endif
	return 0;
}








class TestBases
{
public:
	TestBases()
	{
		cout << "���๹��" << endl;
	}

	~TestBases()
	{
		cout << "��������" << endl;
	}
};

class Tests : public TestBases
{
public:
	Tests()
	{
		cout << "�����๹��" << endl;
	}

	void fun()
	{
		cout << "����������" << endl;
	}

	~Tests()
	{
		cout << "����������" << endl;
	}
};



int test2()
{
	Tests t;

	t.fun();//�ȵ����๹�죬�ٵ����๹��
	        //�ȵ����������������������
	return 0;
}






class TBase1
{
public:
	static int m_s_i;
};

int TBase1::m_s_i = 10;//����̬��������ֵ

class TBase2 : public TBase1
{

};

class TBase3 : public TBase2
{

};

class TBase4 : public TBase3
{

};

int main()
{
	TBase4::m_s_i = 20;

	cout << TBase1::m_s_i;

	return 0;
}