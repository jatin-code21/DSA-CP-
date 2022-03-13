// flag = 0 means left -> right and vice-versa

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

vector<vector<int>> zigzagTraversal(TreeNode *root)
{
	vector<vector<int>> result;
	if (root == NULL) return result;
	queue <TreeNode *> q;
	q.push(root);
	bool leftToRight = true;
	while (!q.empty())
	{
		int size = q.size();
		vector<int> row(size);
		for (int i = 0; i < size; i++)
		{
			TreeNode* node = q.front();
			q.pop();
			int index = leftToRight ? i : (size - 1 - i);
			row[index] = node->data;
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		leftToRight = !leftToRight;
		result.push_back(row);
	}
	return result;	
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