#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ��
//���ʵ�֡�

int main4() {
	int  cover ;
	printf("���������Ǯ��:");
	scanf("%d", &cover);
	int  sum = cover;
	int bottle;
	while (cover != 1) {
		bottle = cover / 2;
		cover = cover%2+cover/2; 
		
		sum += bottle;
		
	}
	printf("���ܹ��õ�����ˮ��  %d  ƿ\n", sum);
	system("pause");
	return 0;
}