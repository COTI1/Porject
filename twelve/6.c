#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int num,i=0,j=2;
	int a[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	printf("请输入你要查找的数字:");
	scanf("%d", &num);
	while (1) {
		if (a[i][j] == num) {
			printf("找到了,(%d,%d)\n", i, j);
			break;
		}
		else if (a[i][j] > num) {
			j--;
		}
		else{
			i++;
		}

		if (i ==4 || j == -1) {
			printf("没有您要查找的数字\n");
			break;
		}
	}
	system("pause");
	return 0;
}