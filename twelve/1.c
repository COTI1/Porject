#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

unsigned int reverse_bit(unsigned int value) {
	unsigned int i,sum = 0, tmp = 0;
	;
	for (i = 0; i < 32; value /= 2, i++) {
		tmp = value % 2;
		sum = sum * 2 + tmp;
		
	}
	return sum;
}





int main1(){
        int num = 0;
		scanf("%d", &num); 
		printf("%u\n",reverse_bit(num));
		system("pause");
		return 0;
}
