#include <iostream>
using namespace std;


//1+2+...+n��if,while,�˳����㷨ʵ��
#if 1
//�߼��������·�ķ���������ifִ���ж�
//1+2+...+n�ĵݹ�� O(n)

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
////��������̬��Ա����ִ�У����ù��캯����O��1��ʵ��
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


