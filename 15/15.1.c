#include<stdio.h>
#include<stdlib.h>


//1.һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ�������ֻ����һ�ε����֣����ʵ�֡�

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