#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB


void round_cat(char * src, int time){
   int len = strlen(src);
   int pos = len - time % len;
   char tmp[256] = { 0 };
   strcpy(tmp, src + pos);
   strncat(tmp, src, pos);
   strcpy(src, tmp);

}



int main1(){
    char str[] = "ABCDEFGHIJKLMN";
    round_cat(str, 10);
    puts(str);
	system("pause");
	return 0;
}