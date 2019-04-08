#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


void reverse_string(char* str)
	{
		if (*str == '\0')
		{
			return;
		}
		reverse_string(str + 1);
		printf("%c", *str);
	}


int main4(){
		char* arr = "abcdefg";
		reverse_string(arr);
		printf("\n");
        system("pause");
        return 0;

}