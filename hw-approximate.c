/*
 * 取近似值
 * 写出一个程序，接受一个浮点数值，输出该数值的近似整数值。
 * 如果小数点后数值大于等于5,向上取整；小于5，则向下取整。
 */

#include <stdio.h>

#define MAXLEN	1000

void get_appr(char * str)
{
	int i = 0, j;

	if (str[0] == '.' || str[0] == '\0') {
		puts("0");
		return;
	}

	while (str[i] != '.' && str[i] != '\0' && i < MAXLEN)
		++i;
	if (str[i] == '.' && str[i + 1] >= '5') {
		int flag = 1;

		j = i - 1;
		while (j >= 0 && flag) {
			if (str[j] == '9') {
				str[j] = '0';
			} else {
				str[j]++;
				flag = 0;
				break;
			}
			--j;
		}
		if (flag == 1)
			printf("1");
	}

	str[i] = '\0';
	printf("%s\n", str);
}

int main(void)
{
	char in[MAXLEN];

	scanf("%s", in);
	get_appr(in);
}
