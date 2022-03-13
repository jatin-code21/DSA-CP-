// Do any traversal on both the trees simulataneously and check wether they are equal or not at every traversal;

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

bool isSame(TreeNode *root1, TreeNode *root2)
{
	if (root1 == NULL || root2 == NULL) return (root1 == root2);
	return (root1->data == root2->data) && isSame(root1->left, root2->left) && isSame(root2->right, root2->right); 
}

int main()
{
	TreeNode *root1 = new TreeNode(5);
	root1->left = new TreeNode(8);
	root1->right = new TreeNode(3);
	root1->left->left = new TreeNode(21);
	root1->left->right = new TreeNode(15);
	root1->right->right = new TreeNode(23);

	TreeNode *root2 = new TreeNode(5);
	root2->left = new TreeNode(8);
	root2->right = new TreeNode(3);
	root2->left->left = new TreeNode(21);
	root2->left->right = new TreeNode(15);
	root2->right->right = new TreeNode(23);	
}

// TC -> O(n) && SC -> O(n);