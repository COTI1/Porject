#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int num,i=0,j=2;
	int a[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	printf("��������Ҫ���ҵ�����:");
	scanf("%d", &num);
	while (1) {
		if (a[i][j] == num) {
			printf("�ҵ���,(%d,%d)\n", i, j);
			break;
		}
		else if (a[i][j] > num) {
			j--;
		}
		else{
			i++;
		}

		if (i ==4 || j == -1) {
			printf("û����Ҫ���ҵ�����\n");
			break;
		}
	}
	system("pause");
	return 0;
}