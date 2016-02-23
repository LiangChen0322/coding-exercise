/*
 * 合唱队: 计算最少出列多少位同学，使得剩下的同学排成合唱队形
 * N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。
 * 合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，
 * 他们的身高分别为T1，T2，…，TK，则他们的身高满足存在i（1<=i<=K）
 * 使得Ti < T2 < ...... < Ti-1 < Ti > Ti+1 > ...... > TK，
 * 也就是按照身高由高到低再由低到高排列。
 * 你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，
 * 可以使得剩下的同学排成合唱队形。
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int *high;
	int *inc, *dec;
	int i, j;
	int ans, ret;

	while (1) {
		if (scanf("%d", &n) == EOF)
			break;
		high = (int *)malloc(sizeof(int) * (n + 1));
		inc = (int *)malloc(sizeof(int) * (n + 1));
		dec = (int *)malloc(sizeof(int) * (n + 1));

		for (i = 0; i < n; i++)
			ret = scanf("%d", high + i);

		inc[0] = 1;
		for (i = 1; i < n; i++) {
			inc[i] = 1;
			for (j = 0; j < i; j++)
				if (high[j] < high[i] && inc[j] + 1 > inc[i])
					inc[i] = inc[j] + 1;
			//printf("inc[%d] : %d\n", i, inc[i]);
		}

		dec[n - 1] = 1;
		for (i = n - 2; i >= 0; i--) {
			dec[i] = 1;
			for (j = n - 1; j > i; j--)
				if (high[j] < high[i] && dec[j] + 1 > dec[i])
					dec[i] = dec[j] + 1;
			// printf("dec[%d] : %d\n", i, dec[i]);
		}

		for (i = 0, ans = 1; i < n; i++)
			if (inc[i] + dec[i] - 1 > ans)
				ans = inc[i] + dec[i] - 1;
		ans = n - ans;
		printf("%d\n", ans);

		free(high);
		free(inc);
		free(dec);
		if (ret == EOF)
			break;
	}

	return 0;
}
