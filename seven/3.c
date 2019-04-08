#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int DigitSum(int n) {
	int i, b = 0;
	for (i = n; i >0; i = i / 10) {
		b = i % 10 + b;
	}
	return b;
}
int main3() {
	int num;
	printf("请输入一个非负整数：");
	scanf("%d", &num);
	int result = DigitSum(num);
	printf("结果为：%d\n", result);
	system("pause");
	return 0;

}