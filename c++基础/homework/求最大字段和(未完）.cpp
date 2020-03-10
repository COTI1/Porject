

/*用动规求最大字段和
int FindGreatestSumOfSubArray(vector<int> array) 
{
	vector<int>tmp(array.size(), 0);
	int maxpre = array[0],tmp = array[0];
	int i;
	for (i = 1; i < array.size(); i++)
	{//当前几个数与当前值相加时和当前值比较，若比当前值大则选用，比当前值小，则改为当前值
		if()
	}
}
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#if 0
int FindGreatestSumOfSubArray(vector<int> array)
{
	int tmp = array[0];
	int maxPre = array[0];

	int i;
	for (i = 1; i < array.size(); i++)
	{
		if (maxPre >= 0)
		{
			maxPre += array[i];
		}
		else
		{
			maxPre = array[i];
		}
		if (tmp < maxPre)
		{
			tmp = maxPre;
		}
	}
	return tmp;
}
#else

int dealGreatestSum(vector<int> &array, int begin, int end)
{
	if (begin == end)
	{
		return array[begin];
	}

	int mid = (begin + end) / 2;
	int leftmax = dealGreatestSum(array, begin, mid);
	int rightmax = dealGreatestSum(array, mid + 1, end);

	int crossmax = 0;

	int i;
	int sum = 0;
	int tmpmax = array[mid];
	for (i = mid; i >= begin; i--)
	{
		sum += array[i];
		if (sum > tmpmax)
		{
			tmpmax = sum;
		}
	}
	crossmax += tmpmax;

	sum = 0;
	tmpmax = array[mid + 1];
	for (i = mid + 1; i <= end; i++)
	{
		sum += array[i];
		if (sum > tmpmax)
		{
			tmpmax = sum;
		}
	}
	crossmax += tmpmax;

	return max(max(leftmax, rightmax), crossmax);
}

int FindGreatestSumOfSubArray(vector<int> array)
{
	return dealGreatestSum(array, 0, array.size() - 1);
}

#endif

int bmain()
{
	int data[] = { 6, -3, -2, 7, -15, 1, 2, 2 };

	vector<int> v(data, data + 8);

	cout << FindGreatestSumOfSubArray(v);

	return 0;
}