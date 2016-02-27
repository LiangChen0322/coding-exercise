/*
 * 华为笔试题: 求int型数据在内存中存储时1的个数
 * 输入一个int型数据，计算出该int型数据在内存中存储时1的个数。
 */
#include <stdio.h>

union data {
	int num;
	char ch[sizeof(int)];
}in;

int count_bits(char ch)
{
	ch = ((ch & 0xaa) >> 1) + (ch & 0x55);
	ch = ((ch & 0xcc) >> 2) + (ch & 0x33);
	ch = ((ch & 0xf0) >> 4) + (ch & 0x0f);
	return ch;
}

int main(void)
{
	int i;
	int ans;

	while (scanf("%d", &in.num) != EOF) {
		ans = 0;
		for (i = 0; i < sizeof(int); i++)
			ans += count_bits(in.ch[i]);
		printf("%d\n", ans);
	}

	return 0;
}
