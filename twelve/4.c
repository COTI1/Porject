#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


//4.
//��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
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