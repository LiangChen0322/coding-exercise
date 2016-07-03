/*
 * 字符串反转
 * 写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。
 */

#include <stdio.h>

#define MAXLEN		1000

void char_invert(char *str)
{
	char *s, *e;
	int ret;

	s = e = str;
	while (*e != '\0')
		++e;
	while (e > s) {
		--e;
		putc(*e, stdout);
	}
	putc('\n', stdout);
}

int main(void)
{
	char in[MAXLEN];

	while(scanf("%s",in) != EOF)
		char_invert(in);

	return 0;
}
