#include<iostream>
#include<vector>
#include<string>
using namespace std;

//ÿ�������ظ�2�Σ�����ѡȡ����1����
int singleNumber1(vector<int>& nums)
{
	int res = 0;
	for (auto &i : nums)
	{
		res ^= i;
	}
	return res;
}
int test1()
{
	int nums[11] = { 1, 5, 6, 3, 5, 2, 1, 8, 6, 3, 8 };
	vector<int> v;
	v.insert(v.begin(), nums, nums + 11);

	cout << singleNumber1(v) << endl;

	return 0;
}


int singleNumber(vector<int>& num)
{

	//�������Σ��ҳ���һ�ε�����  
	int sum = 0, count = 0;
	int i;
	for (i = 0; i < 32; i++)
	{
		for (auto j : num)
		{
			count += j >> i & 1;
		}
		if (count % 3)
		{
			sum |= 1u << i;//1 u  unsigned����
		}
		count = 0;
	}

	return sum;

}


int singleNumber2(vector<int>& nums)
{
	int  sum = 0, tmp = 0;
	for (auto &i : nums)
	{

		//�������Σ��ҳ���һ�ε�����   
		sum = (sum^i)&~tmp;
		tmp = (tmp^i)&~sum;
		//

	}
	return sum;
}


int main()
{
	int nums[10] = { 2, 2, 3, 8, 5, 2, 3, 5, 5, 3 };
	vector<int> v;
	v.insert(v.begin(), nums, nums + 10);

	cout << singleNumber2(v);
	return 0;
}