#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;
//字符串中只出现一次的字符



int findMaxTimesNum(const vector<int>& v)
{
	int counts = 1;
	int num = v[0];

	int i;
	for (i = 1; i < v.size(); i++)
	{
		if (v[i] == v[i - 1])
		{
			counts++;
		}
		else
		{
			if (counts <= 1)
			{
				num = v[i];
			}
			else
			{
				counts--;
			}
		}
	}

	if (v.size() / 2 < count(v.begin(), v.end(), num))
	{
		return num;
	}
	return 0;
}

int main()
{
	int nums[9] = { 2, 2, 2, 5, 5, 2, 3, 3, 2 };
	vector<int> v;
	v.insert(v.begin(), nums, nums + 9);

	cout << findMaxTimesNum(v);


	return 0;
}
