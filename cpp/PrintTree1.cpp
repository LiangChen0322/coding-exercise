/*
 * 剑指offer: 将二叉树打印成多行
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > ans;
		if (pRoot == NULL)
			return ans;

		queue<TreeNode *> q;
		q.push(pRoot);
		do {
			int len = q.size();
			vector<int> vect;

			for (int i = 0; i < len; i++) {
				TreeNode *qt = q.front();
				q.pop();
				vect.push_back(qt->val);
				if (qt->left)
					q.push(qt->left);
				if (qt->right)
					q.push(qt->right);
			}
			ans.push_back(vect);
		} while (!q.empty());
		return ans;
	}
};

void vector_print(vector<vector<int> > vec)
{
	for (int i = 0; i < vec.size(); i++) {
		vector<int>::iterator it;
		for( it = vec[i].begin(); it != vec[i].end(); it++ )
			cout << *it << ' ';
	}
	cout << endl;
}

void test1(void)
{
	Solution sol;
	/*
		8
	 /	  \
	 6	  10
	/\	 / \
	5 7  9 11 */
	TreeNode *tn1 = new TreeNode(8);
	TreeNode *tn2 = new TreeNode(6);
	TreeNode *tn3 = new TreeNode(10);
	TreeNode *tn4 = new TreeNode(5);
	TreeNode *tn5 = new TreeNode(7);
	TreeNode *tn6 = new TreeNode(9);
	TreeNode *tn7 = new TreeNode(11);

	tn1->left = tn2;
	tn1->right = tn3;

	tn2->left = tn4;
	tn2->right = tn5;

	tn3->left = tn6;
	tn3->right = tn7;

	vector<vector<int> > ans = sol.Print(tn1);
	vector_print(ans);
}

int main(void)
{
	test1();
	return 0;
}