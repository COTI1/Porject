#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB


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