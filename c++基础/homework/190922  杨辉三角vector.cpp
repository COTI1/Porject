#include<iostream>
#include<vector>
#include<string>
using namespace std;




void PrintArray(const vector<int>  &v, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
}

//杨辉三角(用一维数组）
void PrintGenerate(int n)
{
	vector<int> v(n, 0);//清0
	v[0] = 1;
	PrintArray(v, 1);//打印第一列的1
	int i, j;
	for (i = 1; i < n; i++)
	{
		for (j = i; j > 0; j--)
		{
			v[j] += v[j - 1];
		}
		PrintArray(v, i + 1);
	}
}



//杨辉三角(用容器）
vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> data(numRows);
	if (numRows == 0)
	{
		return data;
	}
	int i, j;
	data[0].push_back(1);
	for (i = 1; i < numRows; i++)
	{
		data[i] = data[i - 1];
		for (j = i - 1; j > 0; j--)
		{
			data[i][j] += data[i][j - 1];
		}
		data[i].push_back(1);
	}
	return data;
}

//删除排序数组中的重复项

int main()
{
	vector<vector<int>> data = generate(10);

	for (auto &i : data)
	{
		for (auto &j : i)
		{
			cout << j << ' ';
		}
		cout << endl;
	}

	PrintGenerate(10);


	return 0;
}