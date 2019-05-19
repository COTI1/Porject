#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。

int main4() {
	int  cover ;
	printf("请输入你的钱数:");
	scanf("%d", &cover);
	int  sum = cover;
	int bottle;
	while (cover != 1) {
		bottle = cover / 2;
		cover = cover%2+cover/2; 
		
		sum += bottle;
		
	}
	printf("你能够得到的汽水有  %d  瓶\n", sum);
	system("pause");
	return 0;
}