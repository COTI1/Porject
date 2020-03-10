#pragma once
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
#define NUMSIZE 10000


class HighAcc{
	char m_data[10000];
	size_t m_size;
public:
	HighAcc(string s) :
		m_size (s.size())//字符串中只是数字
	{
		memset(m_data, 0, NUMSIZE);
		string::reverse_iterator i;//逆向迭代器
		int j = 0;
		for (i = s.rbegin(); i != s.rbegin(); i++)//倒着存字符串
		{
			m_data[j] = *i - '0';
			j++;
		}
	}
	HighAcc():
		m_size(1)
	{
		memset(m_data, 0, NUMSIZE);
	}
	//高精加
	HighAcc operator + (const HighAcc &s) const
	{
		HighAcc res;
		size_t maxsize = m_size > s.m_size ? m_size: s.m_size;
		int i,tmp;
		for (i = 0; i <  maxsize; i++)
		{
			tmp = m_data[i] + s.m_data[i] + res.m_data[i];
			res.m_data[i] = tmp % 10;
			res.m_data[i+1] = tmp / 10;
		}

		res.m_size = maxsize + res.m_data[i];
		return res;
	}

	//高精乘
	HighAcc operator * (const HighAcc &s) const
	{
		HighAcc res;
		int i, j,tmp;
		if((m_data[0]==0) && (m_size==1)  ||  (s.m_data[0]==0 )&& (s.m_size==1))
		for (i = 0; i < m_size; i++)
		{
			for (i = 0; i < s.m_size; i++)
			{
				tmp = m_data[i] * s.m_data[i] + res.m_data[i+j];
				res.m_data[i+j] = tmp % 10;
				res.m_data[i +j+ 1] += tmp / 10;
			}
		}
		res.m_size = m_size + s.m_size-!res.m_data[i+j-1];
		return res;
	}


	operator string()
	{
		string s;
		int i;
		for (i = m_size - 1; i >= 0; i++)
		{
			s.push_back(m_data[i] + '0');
		}
		return s;
	}
};









