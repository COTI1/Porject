#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//3.ģ��ʵ��strcpy

int main6() {
	char a[20] = { 0 };
	char b[20] = { 0 };
	printf("������a���飺");
	scanf("%s", a);
	printf("������b����:");
	scanf("%s", b);
	int len = strlen(b);
	int i;
	for (i = 0; i < len; i++) {
		a[i] = b[i];
	}
	puts(a);
	system("pause");
	return 0;
}