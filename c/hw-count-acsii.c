/*
 * 字符个数统计
 * 编写一个函数，计算字符串中含有的不同字符的个数。
 * 字符在ACSII码范围内(0~127)。不在范围内的不作统计。
 */
#include <stdio.h>

int count_1_val(char ch)
{
	int res;

	ch = (ch & 0x55) + ((ch & 0xaa) >> 1);
	ch = (ch & 0x33) + ((ch & 0xcc) >> 2);
	res = (ch & 0x0f) + ((ch & 0xf0) >> 4);

	return res;
}

int main(void)
{
	unsigned char hash[16];
	char ch;
	int i;
	int count = 0;

	for (i = 0; i < 16; i++)
		hash[i] = 0;

	while (scanf("%c", &ch) != EOF)
		if (ch < 127) {
			hash[ch / 8] |= 1 << (ch % 8);
		}

	for (i = 0; i < 16; i++)
		count += count_1_val(hash[i]);
	printf("%d\n", count);
}
