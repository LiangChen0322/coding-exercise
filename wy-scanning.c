/*
 * 网易笔试题: 扫描透镜
 * 在N*M的草地上,提莫种了K个蘑菇,蘑菇爆炸的威力极大,兰博不想贸然去闯,
 * 而且蘑菇是隐形的.只 有一种叫做扫描透镜的物品可以扫描出隐形的蘑菇,
 * 于是他回了一趟战争学院,买了2个扫描透镜,一个扫描透镜可以扫描出(3*3)方格中所有的蘑菇,
 * 然后兰博就可以清理掉一些隐形的蘑菇.
 * 问:兰博最多可以清理多少个蘑菇?
 */
#include <stdio.h>

#define MAX_SPC		30

int main(void)
{
	int map[MAX_SPC][MAX_SPC];
	int n, m, k;

	while (scanf("%d%d%d", &n, &m, &k) != EOF) {
		int x, y;
		int i, j, r, s, t;
		int ans = 0;
		int tmp1, tmp2;

		n = n < 3 ? 3 : n;
		m = m < 3 ? 3 : m;

		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				map[i][j] = 0;
		for (i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			map[x - 1][y - 1]++;
		}

		for (i = 0; i <= n - 3; i++) {
			for (j = 0; j <= m - 3; j++) {
				tmp1 = 0;
				for (t = 0; t < 9; t++)
					tmp1 += map[i + (t / 3)][j + (t % 3)];

				for (r = i; r <= n - 3; r++) {
					for (s = j; s <= m - 3; s++) {
						tmp2 = 0;
						for (t = 0; t < 9; t++) {
							if (r + (t / 3) > i + 2 || s + (t % 3) > j + 2)
								tmp2 += map[r + (t / 3)][s + (t % 3)];
						}
						if (tmp1 + tmp2 > ans)
							ans = tmp1 + tmp2;
						// if (tmp1 + tmp2 == 14)
						// 	printf("%d, %d   %d, %d : %d %d\n",
						// 		i, j, r, s, tmp1, tmp2);
					}
				}/* end of for r */
			}
		}/* end of for i */
		printf("%d\n", ans);
	}
}
