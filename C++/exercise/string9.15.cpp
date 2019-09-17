#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include <iostream>     
#include <string>       
using namespace std;

void reverseString(string &s)
{
	int i, j;
	for (i = 0, j = s.size() - 1; i < j; i++, j--)
	{
		swap(s[i], s[j]);
	}
}

int firstUniqchar(string s)
{//计算每个字符出现的次数
	int count[26] = { 0 };
	for (auto &ch : s)
	{
		count[ch - 'a']++;
	}
	//找只出现一次的字符
	for (int i=0;i<s.size();i++)
	{
		if (count[s[i]-'a'] == 1)
			return i;
	}
	return -1;
}

int test(string s)
{
	int num = s.rfind(' ');

	return s.size()-1-num;
}
bool isLettleOrNumber(char ch)
{
	return (ch<'z'&&ch>'a') ||
		   (ch<'Z'&&ch>'A') ||
		   (ch<'9'&&ch>'0');
}

bool Eq(char a,char b)
{
	return a == b ||
		(a | 1 << 5) == (b | 1 << 5);//不区分大小写
}


bool isSame(char a, char b)
{
	return a == b || (a | 1 << 5) == (b | 1 << 5);
}


bool isPalindrome(string s)
{
	string tmp;
	for (auto & ch : s)
	{
		if(isLettleOrNumber(ch))
		{
			tmp.push_back(ch);
		}
	}
	int i, j;
	for (i = 0, j = tmp.size() - 1; i < j; i++, j--)
	{
		if (!isSame(tmp[i], tmp[j]))
		{
			return false;
		}
	}
	return true;
}



int test3()
{
	string str("There are two needles in this haystack with needles");

	string a;
	//cin >> a;
	//reverseString(a);
	cout << test(str)<<endl;
	//cout << a << endl;
	//cout << firstUniqchar(a);
	return 0;
}


int main()
{
	string s("A man, a plan, a canal : Panama");
	//string s("asd");
	cout << isPalindrome(s);
	return 0;
}









int test2()
{
	string s1;

	char str[1000] = { 0 };
	/*C中
	scanf("%[^\n]", str);   //^为非
	scanf("%[0-9]", str);
	scanf("%[a-z]", str);
	fgets(str, 1000, stdin);
*/

/*
getline(cin, s1);//第一个参数为一个输入流
cin.getline(str, 100);//100为最大上限值
*/
//cin>>s1;
	cout << str;


	return 0;

}




int test1()

{

	string str("There are two needles in this haystack with needles.");

	string str2("needle");
	
	//rfind(str)是从字符串右侧(末尾）开始匹配str，并返回在字符串中的位置（下标）；
	cout << str.rfind('a')<< endl;;
	//rfind(str, pos)是从pos开始，向前查找符合条件的字符串
	cout << str.rfind("in", 12) << endl;	
	
	//find(str)是返回第一次匹配字符串的位置，如果没有则返回string::npos
	cout << str.find(str2) << endl;
	cout << str.find("haystack")<< endl;
	
	//find(str, pos)是用来寻找从pos开始(包括pos处字符)匹配str的位置。
	cout << str.find("needles",6) << endl;

   //从位置pos开始，寻找长度为n的字符指针，返回匹配首字符的位置, 没找到返回string::npos
	cout <<  str.find("needles are small", 0, 6)<< endl;
	

  //从位置pos开始，寻找字符c的位置，返回匹配字符的位置, 没找到返回
	cout << str.find('.')<< endl;

//substr截取字符串，从pos位置截取n个
	cout << str.substr(1, 8) << endl;


	str2.operator+=("123");
	str2 + "123";
	cout << str2 << endl;
	return 0;

}
