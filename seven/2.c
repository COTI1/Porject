#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int power(int base,int index) {
	if (index == 0)
		return 0;
	if (index == 1)
		return base;
	else
		return base*power(base, index - 1);
	    
}

int main2() {
	int base=0,index=0;
	printf("���������,ָ����");
	scanf("%d %d", &base,&index);
	int result=power(base,index);
	printf("����ǣ�%d\n", result);
	system("pause");
	return 0;
}