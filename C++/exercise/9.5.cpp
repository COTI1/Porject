#include<iostream>
#include<cstdlib>
using namespace std;
/*
��ʦ����һ��ж�����ˣ�����N�����������ʦ��һ�ο���ͬʱж2��������Ծ���������ж����2*m������
ÿ��ж�����ĵ�����ֵ�ļ��㷽ʽΪ������2������������ֱ���x��y ,�����ĵ�����ֵΪ��x-y��4�η�
���ڸ���N������ֱ������������ʦ��ж��2*m����������ĵ�����ֵ�����Ƕ���
���빲���У���һ��ΪN��M���ڶ�����N������
�����һ�У�Ϊ��С����ֵ
���磺����
  9  4
  1 3 7 9 10 12 17 20 22
���
  64
*/

//����̰���㷨������˼·

/*����˼·��
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
	~test()//��������
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
	
	test *pa = new test(3,6);//��ָ���ָ�����ռ�
	pa->printTest();
	
	
	delete pa;
	return 0;
}