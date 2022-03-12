

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

int maxPathDown(TreeNode *root, int &maxi)
{
	if (root == NULL) return 0;
	int left = max(0, maxPathDown(root->left, maxi)); // here max(0, __) is because if the left or right is giving sum in negative so we dont consider it instead we return 0;
	int right = max(0, maxPathDown(root->right, maxi));

	maxi = max(maxi, left + right + root->data);
	return max(left, right) + root->data;
}

int maxPathSum(TreeNode *root)
{
	int maxi = 0;
	maxPathDown(root, maxi);
	return maxi;
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

