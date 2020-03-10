#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{


/*
   const string s1("Hello");
//4种打印方式
//1
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i];
	}
	cout << endl;
//2
	string::iterator i;
	for (auto i = s1.begin(); i != s1.end(); i++)
	{
		cout << *i;
	}
	cout << endl;
//3
	for (auto &i : s1)
	{
		cout << i;
	}
	cout << endl;
//4
	cout << s1;

*/



	string s1;
	string s2("cai");
	string s3=s2;
	string s4(5,'6');
	s4 += s3;
	s4 += "xukun";



	s1.append("ab");
	s1.append("cde");
	s1.append(3,'5');
	cout << s1<<endl;
	

	cout << typeid(s1).name() << endl;
	cout << typeid(s1.c_str()).name() << endl;







/*
	s1.push_back('1');
	s1.resize(10);
	cout << s1.size() << endl;
	s1.resize(10,'n');
	cout << s1.size() << endl;
	s1.push_back('2');

	s1.resize(6);
	s1.push_back('3');
	cout << s1.size() << endl;
	//s1.clear();
	cout << s1.capacity() << endl;  //clear 不动capacity
	cout << s1.size() << endl;
	
	string::iterator i;
	for ( auto i = s1.begin(); i != s1.end(); i++)
	{
		cout << *i;
	}
	
	
	s1.reserve(500);//给字符串扩容
	
	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl
		 << s4 << endl;

	cout << s1.size() << endl
		<< s2.size() << endl
		<< s3.size() << endl
		<< s4.size() << endl;


	cout << s1.length() << endl
		 << s2.length() << endl
		 << s3.length() << endl
		 << s4.length() << endl;

	cout << s1.capacity() << endl
		 << s2.capacity() << endl
		 << s3.capacity() << endl
		 << s4.capacity() << endl;

	cout << s4.empty() << endl;// 检测字符串释放为空串，是返回true，否则返回false


	s4.clear();//清空有效字符
	cout << s4.size() << endl;
*/

	return 0;
}



