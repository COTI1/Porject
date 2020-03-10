#include"iostream"
using namespace std;
//1��дһ���������ӿڣ�����ɶ�������С��������

void InsertSort(int *src, int n)
{
	int i, j;
	int tmp;
	for (i = 1; i < n; i++)
	{
		tmp = src[i];
		for (j = i; j > 0 && src[j - 1] > tmp; j--)
		{
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}

void InsertSort(float *src, int n)
{
	int i, j;
	float  tmp;
	for (i = 1;i < n; i++)
	{
		tmp = src[i];
		for (j = i; j > 0 && src[j - 1] > tmp; j--)
		{
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}

//2���ӿ��жഫ��һ��ȱʡ�����������ָ�����Ͳ���A����ʽ�����ָ���ˣ��Ͱ�����ѡ���������ʽ�����ٰ������֣���

void sort(int * src, int n, int flag = 0)
{
	switch (flag)
	{
	case 0:
		InsertSort(src,n);
		break;
	case 1:
		break;
	case 2:
		break;
	default:;
	}
}

bool cmpnum(int a,int b)
{
	return a < b;
}

bool cmpwaytest(int a, int b)
{
	return a > b;
}
void InsertSortS(int *src, int n,bool(*cmp)(int ,int)=cmpnum)
{
	int i, j;
	int tmp;
	for (i = 1; i < n; i++)
	{
		tmp = src[i];
		for (j = i; j > 0 && cmp(tmp,src[j - 1]); j--)
		{
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}






int Vmain()
{
	int a[5] = { 5,3,6,9,8 };
	float f[5] = { 8.2,6.3,7.1,9.4,2.6 };
	InsertSort(a, 5);
	InsertSort(f, 5);
	InsertSortS(a, 5,cmpnum); 
	for (auto i : a)
	{
		cout << i <<endl;
	}
	for (auto i : f)
	{
		cout << i <<endl;
	}
	return 0;
}
