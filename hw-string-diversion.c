/*
 * 字符串分隔
 * 连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
 * 长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
 */
#include <stdio.h>
#include <string.h>

void string_div(char *str)
{
	int len = strlen(str);
	int line;
	int i, j;

	if (len == 0)
		return;

	line = len / 8;
	if (len % 8) {
		line++;

		for (i = line * 8 - 1; i >= len; i--) {
			str[i] = '0';
		}
	}

	for (i = 1; i <= line; i++) {
		int e = i * 8;

		for (j = e - 8; j < e; j++)
			printf("%c", str[j]);
		printf("\n");
	}
}

int main(void)
{
	char stra[105], strb[105];

	while (scanf("%s %s", stra, strb) != EOF) {
		string_div(stra);
		string_div(strb);
	}
	return 0;
}
