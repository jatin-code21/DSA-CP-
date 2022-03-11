// Diameter is the longest path betweeen any 2 nodes;
// It is not necessary that it will pass through root;

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

int height(TreeNode *root, int &diameter)
{
	if (root == NULL) return 0;
	int lh = height(root->left, diameter);	
	int rh = height(root->right, diameter);

	diameter = max(diameter, lh + rh);
	
	return max(lh, rh) + 1;
}

int diameterOfBt(TreeNode *root)
{
	int diameter = 0;
	height(root, diameter);
	return diameter;
}



int main()
{
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(8);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(21);
	root->left->right = new TreeNode(15);
	root->right->right = new TreeNode(23);

	cout << diameterOfBt(root);
}

// This is the optimized way of finding the diameter with Time Complexity -> O(N);