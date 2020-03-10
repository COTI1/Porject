#include<iostream>
using namespace std;

//����ģ��
//��̬˳�����֧������,�贫��һ����С
template<class T, size_t N = 10>
class Array
{
	T m_data[N];
public:
	Array()
	{
		cout << N;
	}
};


void test1()
{
	const int i = 100;
	Array<int, i> a;

}






//ԭģ��
template<typename T>
void swapArgs(T & a, T &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//����ģ���ػ�,ģ���һС����ϸ������ԭģ���ߣ�������ԭģ��
template<>
void swapArgs<int>(int & a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//��������
void swapArgs(int & a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void test2()
{
	int a = 5;
	int b = 6;
	swapArgs(a, b);

	cout << a << ' ' << b << endl;
}








template<class T1, class T2>
class Test {
	T1 m_a;
	T2 m_b;
public:
	Test()
	{
		cout << "T1 T2" << endl;
	}
};

//��ģ����ػ�
template<>
class Test <int, char> {
	int m_a;
	char m_b;
public:
	Test()
	{
		cout << "int char" << endl;
	}
};


//ƫ�ػ�
template<class T1>
class Test <T1, double> {
	T1 m_a;
	double m_b;
public:
	Test()
	{
		cout << "T1 double" << endl;
	}
};


//�ػ���ָ��
template<class T1, class T2>
class Test <T1 *, T2 *> {
	T1 * m_a;
	T2 * m_b;
public:
	Test()
	{
		cout << "T1* T2*" << endl;
	}
};

template<class T1, class T2>
class Test <T1 &, T2 &> {
	T1 & m_a;
	T2 & m_b;
public:
	Test(T1 &a, T2 &b) :
		m_a(a),
		m_b(b)
	{
		cout << "T1& T2&" << endl;
		m_a = 8;//a��ı䣬m_a��a��ͬ���ı�����ֻ������һ������
	}
};



void test3()
{
	Test<float, double> t1;
	Test<int, char> t2;
	Test<int *, float *> t3;
	int a = 0;
	char b = 0;
	Test<int &, char&> t4(a, b);

	cout << a << endl;
}







//������ȡ

//������������
class Truetype
{
public:
	static bool get()
	{
		return true;
	}
};
//�����Զ�������
class Falsetype
{
public:
	static bool get()
	{
		return false;
	}
};
//��ģ��
template <class T>
class TypeTraits
{
public:
	typedef Falsetype Jtype;
};
//��ģ���ʵ�����������������Ͷ��ػ�һ��
template <>
class TypeTraits<int>
{
public:
	typedef Truetype Jtype;
};

template <>
class TypeTraits<float>
{
public:
	typedef Truetype Jtype;
};


void test4()
{
	cout << TypeTraits<int>::Jtype::get() << endl;
	cout << TypeTraits<float>::Jtype::get() << endl;//�������ػ��ˣ���Ϊ������Truetype
	cout << TypeTraits<double>::Jtype::get() << endl;//û�б��ػ���Ϊ�Զ�����Falsetype
}






int main()
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}