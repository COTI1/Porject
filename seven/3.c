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
	printf("������һ���Ǹ�������");
	scanf("%d", &num);
	int result = DigitSum(num);
	printf("���Ϊ��%d\n", result);
	system("pause");
	return 0;

}