#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.

//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA

//AABCD右旋一个字符得到DAABC

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