#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//3.模拟实现strcpy

int main6() {
	char a[20] = { 0 };
	char b[20] = { 0 };
	printf("请输入a数组：");
	scanf("%s", a);
	printf("请输入b数组:");
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