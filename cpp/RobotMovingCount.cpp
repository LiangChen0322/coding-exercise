/*
 * 剑指offer: 机器人的运动范围
 * 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
 * 每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标
 * 和列坐标的数位之和大于k的格子。 例如，当k为18时，
 * 机器人能够进入方格（35,37），因为3+5+3+7 = 18。
 * 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
 * 请问该机器人能够达到多少个格子？
 */
#include <iostream>

class Solution {
public:
	int sum(int n)
	{
		int sum = 0;

		do {
			sum += n % 10;
			n = n / 10;
		} while (n);
		return sum;
	}

	int handler(int i, int j, int threshold, int rows, int cols, bool *map)
	{
		if (i < 0 || i >= rows || j < 0 || j>= cols
			|| map[i * cols + j] == true
			|| sum(i) + sum(j) > threshold)
			return 0;
		map[i * cols + j] = true;
		return handler(i - 1, j, threshold, rows, cols, map)
				+ handler(i + 1, j, threshold, rows, cols, map)
				+ handler(i, j - 1, threshold, rows, cols, map)
				+ handler(i, j + 1, threshold, rows, cols, map)
				+ 1;
	}

	int movingCount(int threshold, int rows, int cols)
	{
		bool *map = new bool[rows * cols]();
		int ans = handler(0, 0, threshold, rows, cols, map);
		delete[] map;
		return ans;
	}
};

int main(void)
{
	Solution robot;
	int ans;

	ans = robot.movingCount(3, 10, 10);
	std::cout << ans << std::endl;
	ans = robot.movingCount(10, 10, 10);
	std::cout << ans << std::endl;
	ans = robot.movingCount(6, 30, 30);
	std::cout << ans << std::endl;
}