/*
 * 字符串最后一个单词的长度
 * 计算字符串最后一个单词的长度，单词以空格隔开。
 */
#include <stdio.h>
#include <string.h>

int main()
{
	char in[512];
	int last_len = 0;
	int strl;
	int start, end;

	gets(in);

	strl = strlen(in);
	end = strl - 1;
	while (in[end] == ' ' && end >0)	/* maybe spaces at the end */
		end--;
	start = end;
	while (in[start] != ' ' && start >0)
		start--;
	if (in[start] == ' ')
		last_len = end - start;
	else
		last_len = end - start + 1;
	printf("%d\n", last_len);

	return 0;
}