#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//4.ģ��ʵ��strcat
int main() {
	char a[100] = { 0 };
	char b[20] = { 0 };
	printf("������a���飺");
	scanf("%s", a);
	printf("������b����:");
	scanf("%s", b);
	int len1= sizeof(b);
	int len2 = strlen(a);
	int i;
	for (i = 0; i < len1; i++) {
		a[i+len2] = b[i];
	}
	puts(a);
	system("pause");
	return 0;
}