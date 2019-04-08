#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int mystrlen(char* string){
	if (*string != '\0')
	{
		return 1 + mystrlen(string + 1);
	}
	else
	{
		return 0;
	}
}
	
int main5()
	{
		char string[] = "abcde";
		int ret = mystrlen(string);
		printf("%d\n", ret);
		system("pause");
		return 0;
	}






