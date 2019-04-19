#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


//4.
//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。
//
//	student a am i
//	i ma a tneduts
//	i am a student


void swap(char * str, int i, int j){
  char tmp;
  for (; i < j; i++, j--){
      tmp = str[i];
      str[i] = str[j];
      str[j] = tmp;
  }
}

void reverse_word(char * str){
    int i;
    int start = 0, end = 0;
    for (i = 0; str[i]; i++){
       if (str[i] == ' '){
           end = i - 1;
           swap(str, start, end);
           start = i + 1;
       }
    }
    swap(str, start, i - 1);
    swap(str, 0, i - 1);

}


int main() {
	char str[] = "student a am i";
	reverse_word(str);
	puts(str);
    system("pause");
	return 0;
}