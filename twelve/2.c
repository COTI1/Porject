#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main2(){
	int a=0, b=0;
	printf("���������������ÿո������:");
	scanf("%d %d", &a, &b);
	int c = (a+b) >> 1;
	printf("(%d+%d)/2=%d\n",a,b, c);
	system("pause");
	return 0;
}