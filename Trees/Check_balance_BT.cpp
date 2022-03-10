#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
	int data;
	TreeNode *left,*right;
	TreeNode(int val)
	{
		data = val;
		left = right = NULL;
	}
};

int findLH(TreeNode *root)
{
	if (root == NULL) return 0;
	int Lh = findLH(root->left);
	return 1 + Lh;
}

int findRH(TreeNode *root)
{
	if (root == NULL) return 0;
	int Rh = findRH(root->left);
	return 1 + Rh;
}

bool check(TreeNode *root)
{
	if (root == NULL) return true;
	int lh = findLH(root->left);
	int rh = findRH(root->right);

	if (abs(rh - lh) > 1) return false;

	bool left = check(root->left); // checking the condition for every node height
	bool right = check(root->right);

	if (!(left || right)) return false;
	return true;
}

int main()
{
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(8);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(21);
	root->left->right = new TreeNode(15);
	root->right->right = new TreeNode(23);
}

// This algo has time Complexity of O(n*n);
// The key idea here is that if the difference between left height and right height from any node is greater than 1 than its not the balanced tree;