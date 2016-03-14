/*
 * Microsoft: Divisors
 * Given an integer n, for all integers not larger than n,
 * find the integer with the most divisors.
 * If there is more than one integer with the same number
 * of divisors, print the minimum one.
 *
 * One line with an integer n.
 * For 30% of the data, n ≤ 10^3
 * For 100% of the data, n ≤ 10^16
 * For example input: 100 output: 60
 */

#include <stdio.h>

typedef long long llong;

const unsigned int primes[14] = {2, 3, 5, 7,
				11, 13, 17, 19, 23,
				29, 31, 37, 39, 41};

llong ans, in, maxds;

void dfs(int t, llong now, llong divisors, llong lastni) {
	int i;
	llong temp;

	if (divisors > maxds
			|| (divisors == maxds && now < ans)) {
		maxds = divisors;
		ans = now;
	}

	temp = now * primes[t];
	for (i = 1; ; i++) {
		if (temp > in || i > lastni)
			break;
		dfs(t+1, temp, divisors * (i + 1), i);
		temp = temp * primes[t];
	}
}

int main(void)
{

	while (scanf("%llu", &in) != EOF) {
		ans = 1;
		maxds = 0;
		dfs(0, 1, 1, 100);
		printf("%llu\n", ans);
	}
	return 0;
}
