/*
 * 删除字符串中出现次数最少的字符
 * 实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。
 * 输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
	char in[25];
	int num[26];
	int i;
	int len;
	int least = 100;

	while (scanf("%s", in) != EOF) {
		for (i = 0; i < 26; i++)
			num[i] = 0;

		len = strlen(in);
		for (i = 0; i < len; i++)
			num[in[i] - 'a']++;
		for (i = 0; i < 26; i++)
			if (num[i] != 0 && num[i] < least)
				least = num[i];
		for (i = 0; i < len; i++)
			if (num[in[i] - 'a'] != least)
				putchar(in[i]);
		putchar('\n');
	}
	return 0;
}
