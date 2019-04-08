#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int Factorial(int n) {
	if (n == 0) return 1;
	else
		return n * Factorial(n - 1) ;
}





int main61() {
	int n;
	printf("请输入数字(31以下):");
    scanf("%d", &n);
	int result = Factorial(n);
	printf("%d! = %d\n", n, result);
	system("pause");
	return 0;
}