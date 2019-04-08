#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int fibonacci(int n) {
	if (n <= 2)
		return 1;
	else
		return fibonacci(n - 2) + fibonacci(n - 1);
}




int main11() {
	int n=0;
	int i;
	printf("请输入所要的个数:");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
	    int num=fibonacci(i);
		printf("%d   ", num);
	}	
	printf("\n");
	system("pause");
	return 0;
}