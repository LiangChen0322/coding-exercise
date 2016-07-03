/*
 * 网易笔试题： 升级之路
 * 角色的初始能力值为 a.在接下来的一段时间内,他将会依次遇见n个怪物,每个怪物的防御力为b1,b2,b3...bn.
 * 如果遇到的怪物防御力bi小于等于小易的当前能力值c,那么他就能轻松打败怪物,
 * 并且使得自己的能力值增加bi;如果bi大于c,那他也能打败怪物,但他的能力值只能增加bi与c的最大公约数.
 * 那么问题来了,在一系列的锻炼后,小易的最终能力值为多少?
 */
#include <stdio.h>

int calc_greteast_div(int x, int y)
{
	int c;

	/* 余数不为0，继续相除，直到余数为0 */
	while(y != 0)
	{
		c = x % y;
		x = y;
		y = c;
	}
	return x;
}

int main(void)
{
	int n, a;
	int b[100000];
	int i;

	while (scanf("%d %d", &n, &a) != EOF) {
		for (i = 0; i < n; i++)
			scanf("%d", b + i);

		for (i = 0; i < n; i++) {
			if (b[i] <= a)
				a += b[i];
			else
				a += calc_greteast_div(a, b[i]);
		}
		printf("%d\n", a);
	}

	return 0;
}
