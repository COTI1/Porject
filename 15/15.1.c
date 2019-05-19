#include<stdio.h>
#include<stdlib.h>


//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个只出现一次的数字，编程实现。

int main3() {
	int a[] = { 6,1,1,6,3,3,2 };
	int len = sizeof(a) / sizeof(a[0]);
	int num = 0;
	int i;
	for (i = 0; i < len; i++) {
		num ^= a[i];
	}
	printf("%d\n", num);
	system("pause");
	return 0;
}