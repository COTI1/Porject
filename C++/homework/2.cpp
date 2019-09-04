#include"iostream"
using namespace std;


//1���ֱ�ʹ�����úͺ���ɽ���������ʹ�������������������ͬ
//2������ָ���ĺ�����������ɺ�����
//a����һ���ַ���ת��Ϊ���֣�����ֵ����У��ת���Ƿ�ɹ�

bool strtoi(const char * src, int &res)
{
    if (!src)
	{
		return false;
	}
	while (*src <= ' ')
	{
		src++;
	}
	int flag = 1;
	if (*src == '-')
	{
		flag = -1;
		src++;
	}
	if (*src > '9' || *src < '0')
	{
		return false;
	}
	int sum = 0, tmp;
	int i;
	for (i = 0; src[i] <= '9' && src[i] >= '0'; i++)
	{
		tmp = src[i] - '0';
		sum = sum * 10 + tmp;
	}
	res = sum * flag;
	return true;

}



//b����һ������ͨ��ָ�����ư�λ����ֱ�Ӹ���ԭ����

void sysReverse(int &num, int hex)
{
	int i;
	int tmp, sum = 0;
	for (i = num; i; i /= hex)
	{
		tmp = i % hex;
		sum = sum * hex + tmp;
	}
	num = sum;
}

int Fmain()
{
	int res;
	int num = 1723;
	sysReverse(num, 16);
	cout << num << endl;
	if (strtoi("\n\n\a\a\r\r\t\t\b\b   -478a193", res))
	{
		cout << res << endl;
	}
	else
	{
		cout << "fail\n";
	}
	return 0;
}