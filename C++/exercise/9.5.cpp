#include<iostream>
#include<cstdlib>
using namespace std;
/*
王师傅是一名卸货工人，现有N个货物，由于王师傅一次可以同时卸2个货物，所以决定今天先卸其中2*m个货物
每次卸货消耗的体力值的计算方式为，假如2个货物的质量分别是x和y ,则消耗的体力值为（x-y）4次方
现在给出N个货物分别的质量，求王师傅卸完2*m个货物后消耗的体力值最少是多少
输入共两行，第一行为N和M，第二行是N个数字
输出共一行，为最小体力值
例如：输入
  9  4
  1 3 7 9 10 12 17 20 22
输出
  64
*/

//不能贪心算法，动规思路

/*解题思路：
   f[i][j]=min(f[i-2][j-1]+pow((d[i]-d[i-1],4)  ,  f[i-1][j])

     
n 		0	1	2	3	4
0	/	0	MAX	MAX	MAX	MAX
1	2	0	16	MAX	MAX	MAX
2	4	0	16	MAX	MAX	MAX
3	2	0	16	32	MAX	MAX
4	1	0	1	17	MAX	MAX
5	2	0	1	17	48	MAX
6	5	0	1	17	48	MAX
7	3	0	1	17	48	129
8	2	0	1	17	33	64

*/

class test
{
	int m_a;
	int m_b;
	int * m_pt;
public:
	test() :
		m_a(0),
		m_b(0)
	{
		m_pt = new int;
	}

	test(int a,int b) :
		m_a(a),
		m_b(b)
	{
		m_pt = new int;
	}
	~test()//析构函数
	{
		delete m_pt;
	}
	void printTest()
	{
		cout << m_a << ' ' << m_b << endl;
	}
};
int fmain()
{
	/*
	const int i = 2;
	printf("%p\n", &i);
	*((int *)&i) = 4;
	printf("%d", i);
   */
	test a;
	//test *pa = (test*)malloc(sizeof(test));   free(pa); //C
	
	test *pa = new test(3,6);//给指针的指向分配空间
	pa->printTest();
	
	
	delete pa;
	return 0;
}