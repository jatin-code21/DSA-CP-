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

int heightOfBt(TreeNode *root)
{
	if (root == NULL) return 0;
	int lh = heightOfBt(root->left);
	if (lh == -1) return -1;

	int rh = heightOfBt(root->right);
	if (rh == -1) return -1;

	if (abs(lh - rh) > 1) return -1;

	return max(lh, rh) + 1;
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

// Here the basic idea is that if the abs(lh - rh) > 1 then as its not balance BT so we return -1 or else we will be returning the height of BT;