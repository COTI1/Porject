#include <iostream>
#include<cstdio>
using namespace std;



//字符共256个
int main() {
	unsigned char c = 7;
	int j = 0;
	for (; c > 0; c -= 3)
	{
		j++;
	}

	printf("%d  ", j);
	return 0;
}



/*Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i - 1] + F[i - 2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，
在Fibonacci数列中的数我们称为Fibonacci数。
给你一个N，你想让其变为一个Fibonacci数，
每一步你可以把当前数字X变为X - 1或者X + 1，
现在给你一个数N求最少需要多少步可以变为Fibonacci数。
*/






int bmain()
{

#if 1
	int N;
	cin >> N;
	if (N < 0 && N>1000000)
	{
		return 0;
	}

	int F[100000];
	F[0] = 0;
	F[1] = 1;
	int i;
	int count = 0;
	int j = 0, k = 0;
	for (i = 2; i < 100; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
		if (N == F[i])
		{
			cout << 0;
			return 0;
		}
		if (N < F[i])
		{
			cout << F[i] << "  ";
			cout << F[i - 1] << endl;

			int NUM = N;
			while (NUM != F[i - 1])
			{
				NUM--;
				k++;
			}
			while (N != F[i])
			{
				N++;
				j++;
			}

			if (k > j)
			{
				cout << j;
			}
			else
				cout << k;
			break;
		}
	}



#elif 0
	 int N;
	 cin >> N;
	 int a = 0, b = 1;
	while (b <= N) {
		int b_temp = b + a;
		a = b;
		b = b_temp;
	}
	cout<<((b - N) > (N - a) ? N - a : b - N);
	


#else

	int num = 0;
	cin>>num;
	int f1 = 0, f2 = 1, f3 = f1 + f2;
	while (1) {
		if (f2 == num)
		{
			cout<< 0;
			break;
		}
		else if (f2 > num)
		{
			if (abs(f2 - num) > abs(f1 - num))
			{
				cout << (abs(f1 - num));
			}
			else
			{
				cout<<( abs(f2 - num));
			}
			break;
		}
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
	}



#endif

	return 0;
}