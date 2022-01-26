#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void inorderIterative(TreeNode *root)
{
    vector<int> inorder;
    stack<TreeNode *> stk;
    TreeNode *node = root;
    while (true)
    {
        if (node != NULL)
        {
            stk.push(node);
            node = node->left;
        }
        else
        {
            if (stk.empty())
                break;
            node = stk.top();
            stk.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    inorderIterative(root);
}