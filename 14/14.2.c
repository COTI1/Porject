#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.

//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA

//AABCD����һ���ַ��õ�DAABC

int compare(char* stri,char* strj) {
	char temp[258] = { 0 };
	strcpy(temp, stri);
	strcat(temp, stri);
	if (strlen(stri) == strlen(strj)) {
		return strstr(temp, strj) ? 1 : 0;
	}
	else
		return 0;
}

int main2() {
	char str[] = "ABCDEFGHIJKLMN";
	char str2[] = "BCDEFGHIJKLMNA";
	int d=compare(str,str2);
	printf("%d\n", d);
	system("pause");
	return 0;
}