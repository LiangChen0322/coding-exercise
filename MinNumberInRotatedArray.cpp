/*
 * 剑指offer： 旋转数组的最小数字
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int n = rotateArray.size();
		if(n == 0)
			return 0;
		long low=0, high=n-1, mid;
		while(low+1 < high)
		{
			mid=(low+high)>>1;
			if(rotateArray[mid] == rotateArray[low]
					&& rotateArray[mid] == rotateArray[high])
				low++;
			else if(rotateArray[mid] >= rotateArray[low]
					&& rotateArray[mid] <= rotateArray[high]
					|| rotateArray[mid] <= rotateArray[low]
					&& rotateArray[mid] < rotateArray[high]) {
				high=mid;
			} else
				low=mid;
		}
		return rotateArray[low]<rotateArray[high]?rotateArray[low]:rotateArray[high];
	}
};

int main(void)
{
	int a[12] = {5, 5, 5, 5, 5, 5, 2, 3, 5, 5, 5, 5};
	vector<int> Array(a, a + 12);
	int min;

	Solution rotate;
	min = rotate.minNumberInRotateArray(Array);

	std::cout << min << "\n";
	return 0;
}