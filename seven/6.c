#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main6() {
	int n=0,i;
	int result = 1;
	printf("请输入数字(31以下):");
	scanf("%d",&n);
	for (i = 1; i <=n; i++) {
		result = result * i;
	}
	printf("%d! = %d\n", n, result);
	system("pause");
	return 0;
}