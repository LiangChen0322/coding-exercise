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

#include <iostream>

using namespace std;

typedef long long ll;

long prime[] = {2, 3, 5, 7, 11, 13, 17,
            19, 23, 29, 31, 37, 41};
ll result, n, maxDivisors;

void dfs(long t,ll now,ll divisors,ll lastNi){
	if(divisors > maxDivisors
			|| (divisors == maxDivisors && now < result)){
		maxDivisors = divisors;
		result = now;
	}

	int i = 1;
	ll temp = now * prime[t];
	do {
		if (temp > n || i > lastNi)
			break;
		dfs(t+1, temp, divisors * (i + 1), i);
		i++;
		temp = temp * prime[t];
	} while (1);
}
int main()
{
	cin >> n;
	maxDivisors = 0;
	dfs(0, 1, 1, 100);
	cout << result << endl;
	return 0;
}
