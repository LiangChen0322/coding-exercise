/*
 * 剑指offer: 二叉树的镜像
 */
#include <iostream>

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
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL)
			return;

		if (pRoot->left)
			Mirror(pRoot->left);
		if (pRoot->right)
			Mirror(pRoot->right);
		TreeNode *tt = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tt;
	}
};

void printTree(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return;

	cout << pRoot->val << '\t';
	if (pRoot->left)
		printTree(pRoot->left);
	if (pRoot->right)
		printTree(pRoot->right);
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

	printTree(tn1);
	cout << endl;
	sol.Mirror(tn1);
	printTree(tn1);
	cout << endl;
}

int main(void)
{
	test1();
	return 0;
}
