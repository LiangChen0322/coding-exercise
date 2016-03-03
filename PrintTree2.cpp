/*
 * 剑指offer: 按之字形顺序打印二叉树
 */
#include <iostream>
#include <vector>
#include <stack>

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
		vector<vector<int> > vans;
		if (pRoot == NULL)
			return vans;

		stack<TreeNode *> s1, s2;
		s1.push(pRoot);
		while (!s1.empty() || !s2.empty()) {
			if (!s1.empty()) {
				vector<int> vi;
				while (!s1.empty()) {
					TreeNode *tt = s1.top();
					s1.pop();
					vi.push_back(tt->val);
					if (tt->left)
						s2.push(tt->left);
					if (tt->right)
						s2.push(tt->right);
				}
				vans.push_back(vi);
			}

			if (!s2.empty()) {
				vector<int> vi;
				while (!s2.empty()) {
					TreeNode *tt = s2.top();
					s2.pop();
					vi.push_back(tt->val);
					if (tt->right)
						s1.push(tt->right);
					if (tt->left)
						s1.push(tt->left);
				}
				vans.push_back(vi);
			}
		}
		return vans;
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
