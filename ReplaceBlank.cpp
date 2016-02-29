/*
 * 剑指offer: 替换空格
 */
#include <iostream>

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL && length <= 0)
			return;

		int len = 0;
		int blockn = 0;
		int i;

		for (len = 0; str[len] != '\0'; len++)
			if (str[len] == ' ')
				++blockn;
		i = len + blockn * 2;
		if (i > length)
			return;

		for ( ; len >= 0; len--) {
			if (str[len] == ' ') {
				str[i--] = '0';
				str[i--] = '2';
				str[i--] = '%';
			} else {
				str[i--] = str[len];
			}
		}
	}
};

int main(void)
{
	int len;
	char str1[20] = {"1 2 3 4"};
	char str2[20] = {" "};
	char str3[20] = {"abc abc "};

	Solution rep;

	rep.replaceSpace(str1, 20);
	std::cout << str1 << std::endl;
	rep.replaceSpace(str2, 20);
	std::cout << str2 << std::endl;
	rep.replaceSpace(str3, 20);
	std::cout << str3 << std::endl;

	return 0;
}
