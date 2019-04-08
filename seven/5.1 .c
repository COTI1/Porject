#include<stdio.h>
#include<stdlib.h>
int mstrlen(char* string)
{
	int count = 0;
	while (*string != '\0')
	{
		count++;
		string++;
	}
	return count;
}
int main()
{
	char string[] = "abcde";
	int ret = mstrlen(string);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
