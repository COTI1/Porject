#include<iostream>
#include<cstdlib>
using namespace std;
/*
3�������½ṹ��

struct student {
	char name[32];
	int age;
	int class;
	bool sex;
};

д���������ú������صķ�ʽ��д����ͳ�Ƴ�һ���������ṹΪ��׼�Ľṹ�������У�
1������ΪX�ĳ����˶��ٴ�
2������ΪX�ĳ����˶��ٴ�
3���༶ΪX�ĳ����˶��ٴ�
4���Ա��X�ĳ����˶��ٴ�


���磺����ΪX�Ŀ�����������������
int countName(student * src, int n, char * name);
tip:���Կ�����ȱʡ�����ķ�ʽ�����߻ص������ķ�ʽʵ��*/

struct student {
	char name[32];
	int age;
	int classid;
	bool sex;
};
bool cmpEql(student a, student b)
{
	return a.age = b.age;
}
bool cmpEqlname(student a, student b)
{
	return strcmp(a.name,b.name)? false:true;
}
bool cmpEqlsex(student a, student b)
{
	return a.sex = b.sex;//   !(a.sex ^ b.sex);
}
int countS(student *st, int n, student value, bool(*cmp)(student , student)=cmpEql)
{
	int i;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		if (cmp(st[i], value))
		{
			count++;
		}
	}
	return count;
}


int Amain()
{
	student st[] = { {"qw",23,1,true },
	{"fe",32,1,true},
	{"klqw",86,1,true},
	{"qw",23,1,true},
	{"fg",34,1,true},
	{"re",32,1,true},
	{"bv",54,1,false },
	};
	
	student test = { "qw",23,1,true };
	cout << countS(st,7,test, cmpEqlname) << endl;
	system("pause");
	return 0;
}