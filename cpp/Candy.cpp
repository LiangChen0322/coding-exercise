/*
 * LeetCode(135): Candy
 * There are N children standing in a line. Each child is assigned a rating value.
 * You are giving candies to these children subjected to the following requirements:
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 * https://leetcode.com/problems/candy/
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		int num = ratings.size();
		vector<int> ca(num, 1);
		int ans = 0;

		for (int i = 1; i < num; i++)
			if (ratings[i] > ratings[i - 1])
				ca[i] = ca[i - 1] + 1;
		for (int i = num - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1]
				&& ca[i] < ca[i + 1] + 1)
				ca[i] = ca[i + 1] + 1;
			ans += ca[i];
		}
		return ans + ca[num - 1];
	}
};

void test(int *array, int num)
{
	int ans;
	Solution tar;

	vector<int> test(array, array + num);
	cout << tar.candy(test) << endl;
}

int main()
{
	int a1[5] = {1, 2, 3, 4, 5};
	int a2[5] = {5, 4, 3, 2, 1};
	int a3[5] = {2, 2, 2, 2, 2};
	int a4[7] = {1, 2, 3, 4, 3, 2, 1};

	test(a1, 5);
	test(a2, 5);
	test(a3, 5);
	test(a4, 7);
	return 0;
}