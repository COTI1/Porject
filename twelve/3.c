
#include<stdio.h>
#include<stdlib.h>
int find_single(int a[20],int b) {
	int i,c=a[0];
	for (i = 1; i < b; i++) {
		c ^= a[i];
	}
	return c;
}
int main3() {
	int a[10] = { 2,2,5,5,3,6,6 };
	int b = sizeof(a) / sizeof(a[0]);
	printf("%d\n",find_single(a,b));
	system("pause");
	return 0;
}

