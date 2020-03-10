#include <iostream>
using namespace std;


//1+2+...+n无if,while,乘除的算法实现
#if 1
//逻辑运算符短路的方法来代替if执行判断
//1+2+...+n的递归版 O(n)

int Sum_Solution(int n)
{
	int a = 1;
	n > 1 && (a = n + Sum_Solution(n - 1));
	return a;
}

int main()
{
	cout << Sum_Solution(100);

	return 0;
}



#else
////用两个静态成员变量执行，调用构造函数，O（1）实现
class test
{
public:
	static int s_m_tmp;
	static int s_m_sum;

	test()
	{
		s_m_tmp++;
		s_m_sum += s_m_tmp;
	}
};

int test::s_m_tmp = 0;
int test::s_m_sum = 0;

int main()
{
	test * t = new test[100];

	cout << test::s_m_sum;

	delete[] t;

	return 0;
}


#endif


