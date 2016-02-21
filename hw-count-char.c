/*
 * 计算字符个数
 * 写出一个程序，接受一个有字母和数字以及空格组成的字符串，
 * 和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
 */
#include <stdio.h>

int main(void)
{
	char in[512];
	char ch, cht;
	int count = 0;
	int i;

	gets(in);
	ch = (char)getc(stdin);
	if (ch >= 'A' && ch <= 'Z')
		cht = ch - ('A' - 'a');
	else
		cht = ch + ('A' - 'a');

	for (i = 0; i < 512; i++) {
		if (in[i] == '\0')
			break;
		if (in[i] == ch || in[i] == cht)
			count++;
	}
	printf("%d\n", count);

	return 0;
}
