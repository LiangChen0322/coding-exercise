/*
 * Write a function that takes a string as input and returns the string reversed.
 * Example:
 * Given s = "hello", return "olleh".
 */
#include <iostream>

#define CHOOSE		1

using namespace std;

class Solution {
public:
	string reverseString(string s) {
#if 1
		int len = s.size();

		if (len < 1)
			return s;
		for (int i = 0, j = len -1; i <= j; ++i, --j) {
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		}
#else
		return string(s.rbegin(), s.rend());
#endif
		return s;
	}
};

void TestHandler(string s)
{
	Solution sol;

	s = sol.reverseString(s);
	cout << s << endl;
}

void Test1()
{
	string s = "hello world";
	TestHandler(s);
}

int main(void)
{
	Test1();

	return 0;
}
