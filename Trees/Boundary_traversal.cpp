// Anti-cloclwise boundary traversal

//1-> left boundary excluding leaf;
//2-> Leaf nodes
//3-> Right boundary in reverse excluding lead;


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

bool isLeaf(TreeNode *root)
{
	if (!root->left && !root->right)
	{
		return true;
	}
	return false;
}

void addLeftboundary(TreeNode *root, vector<int> &res)
{
	TreeNode *cur = root->left;
	while (cur)
	{
		if (!isLeaf(root)) res.push_back(cur->data);
		if (cur->left) cur = cur->left;
		else cur = cur->right;
	}
}

void addRightBoundary(TreeNode *root, vector<int> &res)
{
	TreeNode *cur = root->right;
	vector<int> temp;
	while (cur)
	{
		if (!isLeaf(root)) temp.push_back(cur->data);
		if (cur->right) cur = cur->right;
		else cur = cur->left;
	}
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		res.push_back(temp[i]);
	}
}

void addLeaves(TreeNode *root, vector<int> &res)
{
	if (isLeaf(root))
	{
		res.push_back(root->data);
		return;
	}
	if (root->left) addLeaves(root->left, res);
	if (root->right) addLeaves(root->right, res);
}

vector<int> printBoundary(TreeNode *root)
{
	vector<int> res;
	if (!root) return res;
	if (!isLeaf(root)) res.push_back(root->data);
	addLeftboundary(root, res);
	addLeaves(root, res);
	addRightBoundary(root, res);
	return res;
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

// TC -> O(n) && SC -> O(n);