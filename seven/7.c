#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void print(int n)
{
	if (n < 10)
	{
		printf("%d ", n);
	}
	else
	{
		print(n / 10);
		printf("%d ", n % 10);
	}
}



int main7() {
	int n=0;
	printf("请输入一个数字：");
	scanf("%d", &n);
	print(n);
	printf("\n");
    system("pause");
	return 0;
}




