/*
 * Josephus Problem 约瑟夫问题
 * n个人编号 0 ~ n-1, 站成一排报数， 逢k淘汰。
 * 求最后留下的编号。
 */
#include <stdio.h>

long long Josephus_hdlr(long long n, long long k)
{
	long long ret;
	long long i;

	if (n <= 1)
		return 0;

	if (n < k) {
		ret = 0;
		for (i = 2; i <= n; i++)
			ret = (ret + k) % i;
		return ret;
	}
	ret = Josephus_hdlr(n - n / k, k);
	if (ret < n % k)
		ret = ret - n % k + n;
	else
		ret = ret - n % k + (ret - n % k) / (k - 1);
	return ret;
}

int main(void)
{
	long long n, k;
	int t, i;

	while (scanf("%d", &t) != EOF) {
		for (i = 0; i < t; i++) {
			scanf("%lld%lld", &n, &k);
			printf("%lld\n", Josephus_hdlr(n, k));
		}
	}

	return 0;
}
