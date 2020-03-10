#include<iostream>
#include<string>
using namespace std;

int bvmain()
{
	string s1;
	cin >> s1;
	int i, j;

	for (i = s1.length()-1; i >= 0; i--)
	{
		if (((s1[i] < 'A') || (s1[i] > 'z') )&& (s1[i] != ' '))
		{
			return 0;
		}
		else
		{
			for (j = 0; j < i; j++)
			{
				if (s1[i] == s1[j])
				{
					s1[i] = ' ';
				}
			}
		}		
	}
	for (i = 0; i < s1.length(); i++)
	{
		if (s1[i] != ' ') {
			cout << s1[i] ;
		}		
	}
	
	return 0;
}









int main()
{
	string s1;
	cin >> s1;
	string dst;
	int i;
	for (i =0 ; i <s1.length() ; i++)
	{
		
		if ((s1[i] < 'A') || (s1[i] > 'z')) 
		{
			return 0;
		}
		
		if (dst.find(s1[i]) == -1)
		{
			dst.push_back(s1[i]);
		}
		
		
	}
	/*
	for (auto &i : s1)
	{
		if (dst.find(i) == -1)
		{
		   dst.push_back(i);
		}	    
	}*/
	cout << dst;
	return 0;
}