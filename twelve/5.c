#include <stdio.h>
#include<stdlib.h>
int main5()

{
	int i, j,tmp=0;
	int a[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (i=0;i<9;i++){
		for (j = 8; j >= 0; j--) {
			if(a[j]%2==1 && a[i]%2==0 && i<=j){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}



	for (i = 0; i < 9; i++){
          printf("%d ", a[i]);
    }
	system("pause");
     return 0;

}