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
{//����ÿ���ַ����ֵĴ���
	int count[26] = { 0 };
	for (auto &ch : s)
	{
		count[ch - 'a']++;
	}
	//��ֻ����һ�ε��ַ�
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
		(a | 1 << 5) == (b | 1 << 5);//�����ִ�Сд
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
	/*C��
	scanf("%[^\n]", str);   //^Ϊ��
	scanf("%[0-9]", str);
	scanf("%[a-z]", str);
	fgets(str, 1000, stdin);
*/

/*
getline(cin, s1);//��һ������Ϊһ��������
cin.getline(str, 100);//100Ϊ�������ֵ
*/
//cin>>s1;
	cout << str;


	return 0;

}




int test1()

{

	string str("There are two needles in this haystack with needles.");

	string str2("needle");
	
	//rfind(str)�Ǵ��ַ����Ҳ�(ĩβ����ʼƥ��str�����������ַ����е�λ�ã��±꣩��
	cout << str.rfind('a')<< endl;;
	//rfind(str, pos)�Ǵ�pos��ʼ����ǰ���ҷ����������ַ���
	cout << str.rfind("in", 12) << endl;	
	
	//find(str)�Ƿ��ص�һ��ƥ���ַ�����λ�ã����û���򷵻�string::npos
	cout << str.find(str2) << endl;
	cout << str.find("haystack")<< endl;
	
	//find(str, pos)������Ѱ�Ҵ�pos��ʼ(����pos���ַ�)ƥ��str��λ�á�
	cout << str.find("needles",6) << endl;

   //��λ��pos��ʼ��Ѱ�ҳ���Ϊn���ַ�ָ�룬����ƥ�����ַ���λ��, û�ҵ�����string::npos
	cout <<  str.find("needles are small", 0, 6)<< endl;
	

  //��λ��pos��ʼ��Ѱ���ַ�c��λ�ã�����ƥ���ַ���λ��, û�ҵ�����
	cout << str.find('.')<< endl;

//substr��ȡ�ַ�������posλ�ý�ȡn��
	cout << str.substr(1, 8) << endl;


	str2.operator+=("123");
	str2 + "123";
	cout << str2 << endl;
	return 0;

}
