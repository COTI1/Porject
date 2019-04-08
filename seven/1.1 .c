#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main1() {
	int num,i,tmp;
	int a = 1;
	int b = 1;
	printf("请输入所要的个数:");
	scanf("%d", &num);
	printf("%d   %d   ", a, b);
	for (i = 1; i <= num-2; i++) {
		tmp = b;
		b = a + b;
		a = tmp;
		printf("%d   ",b);
		
	}
	printf("\n");
	system("pause");
	return 0;
}