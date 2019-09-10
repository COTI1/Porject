#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>
class Test
{
	T m_a;
public:
	Test(T s=0) :
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







//模板
template <class T>void swapArgs(T &a,T &b)
{
	T tmp;
	//cout << typeid(tmp).name() << endl;
	tmp = a;
	a = b;
	b = tmp;
}

//可以对模板进行部分重载，函数调用int时，调用此函数，调用其他型则用模板
void swapArgs(int &a, int &b){
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

int main()
{/*
	int a = 5, b = 3;
	double as = 3.4, bc = 3.5;
	swapArgs(a, b);
	cout << a <<' '<< b << endl;
	//调用模板
	swapArgs<int>(a, b);
	cout << a << ' ' << b << endl;
	swapArgs(as, bc);
	cout << as << ' ' << bc << endl;

	
	int arr[] = { 1,2,3,4,8,6,5 };
	cout << findArgs(arr, 7, 3)<<endl;
	
	
	cout << add<int>(3, 1)<<endl;
*/
	Test<int> ad(6);
	ad.showData();

	return 0;
}