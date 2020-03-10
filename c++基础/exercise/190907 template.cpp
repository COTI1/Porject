#include<iostream>
using namespace std;

template<class T>
class Test
{
	T m_a;
public:
	Test(T s = 0) :
		m_a(s)
	{

	}
	void setData(T s);

	void showData()
	{
		cout << m_a << endl;
	}
};


template<class T>
void Test<T>::setData(T s)
{
	m_a = s;
}

int test1()
{
	Test<int> a(6);
	a.setData(8);
	a.showData();

	return 0;
}



//模板
template <class T>
void swapArgs(T &a, T &b)
{
	T tmp;
	//cout << typeid(tmp).name() << endl;
	tmp = a;
	a = b;
	b = tmp;
}

//可以对模板进行部分重载，函数调用int时，调用此函数，调用其他型则用模板
void swapArgs(int &a, int &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

template <typename T>
int findArgs(T* src, size_t n, T f)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (src[i] == f)
		{
			return i;
		}
	}
	return -1;
}


template <typename T>
T add(T a, T b)
{
	return a + b;
}


template <typename T1, typename T2>
T1 add(T1 a, T2 b)
{
	return a + b;
}

int add(int a, int b)
{
	return a + b;
}

int main()
{
	int a = 5, b = 3;
	double as = 3.4, bc = 3.5;

	swapArgs(a, b);//调用函数
	cout << a << ' ' << b << endl;
	/*
	swapArgs<int>(a, b);//调用模板
	cout << a << ' ' << b << endl;
	swapArgs(as, bc); //调用模板
	cout << as << ' ' << bc << endl;
	char aq = 'a', ba = 'b';
	swapArgs(aq, ba); //调用模板
	cout << aq << ' ' << ba << endl;



	int arr[] = { 4,2,6,8,1,5,9 };
	cout << findArgs(arr, 7, 3)<<endl;


	cout << add<int>(3, 1)<<endl;
*/

	return 0;
}