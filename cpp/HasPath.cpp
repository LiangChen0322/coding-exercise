/*
 * 剑指offer: 矩阵中的路径
 */
#include <iostream>

using namespace std;

class Solution {
public:
	bool hasPathCore(char* matrix, int rows, int cols, char* str,
				   int row, int col, bool *map)
	{
		if (*str == '\0')
			return true;		if (row < 0 || row >= rows || col < 0 || col >= cols
			|| matrix[row * cols + col] != *str
			|| map[row * cols + col])
			return false;
		map[row * cols + col] = true;

		++str;
		if (hasPathCore(matrix, rows, cols, str, row + 1, col, map)
			|| hasPathCore(matrix, rows, cols, str, row - 1, col, map)
			|| hasPathCore(matrix, rows, cols, str, row, col + 1, map)
			|| hasPathCore(matrix, rows, cols, str, row, col - 1, map)){
			// cout << "row:" << row << " col:" << col << endl;
			return true;
		} else {
			map[row * cols + col] = false;
			return false;
		}
	}

	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				bool *map = new bool[rows * cols]();
				if (hasPathCore(matrix, rows, cols, str, i, j, map))
					return true;
			}
		}
		return false;
	}
};

void test(char* matrix, int rows, int cols, char* str)
{
	Solution sol;

	if (sol.hasPath(matrix, rows, cols, str))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

int main(void)
{
	char m1[] = {"abcdefghi"};
	char s1[] = {"abc"};
	char m2[] = {"ABCESFCSADEE"};
	char s2[] = {"ABCCED"};

	test(m1, 3, 3, s1);
	test(m2, 3, 4, s2);

	return 0;
}