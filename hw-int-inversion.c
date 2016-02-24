/*
 * 数字颠倒
 * 输入一个整数，将这个整数以字符串的形式逆序输出
 * 程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，
 * 如输入为100，则输出为001
 */
#include <stdio.h>

long int_invert(long n)
{
	long di = 1;
	long i = 1;
	long res = 0;

	while (n / (di * 10000))
		di *= 10000;
	do {
		di *= 10;
	} while (n / di);
	di /= 10;

	while (i <= di) {
		res *= 10;
		res += (n / i) % 10;
		i *= 10;
	}
	return res;
}

int main(void)
{
	long in;

	while (scanf("%ld", &in) != EOF) {
		in = int_invert(in);
		printf("%ld\n", in);
	}
}
