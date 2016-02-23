/*
 * 质数因子
 * 功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子
 * 如180的质数因子为2 2 3 3 5
 */
#include <stdio.h>

int main(void)
{
	long i = 2;
	long num;

	scanf("%ld", &num);
	while (num != 1) {
		if (num % i == 0) {
			num /= i;
			printf("%ld ", i);
		} else {
			i++;
		}
	}
	printf("\n");
}
