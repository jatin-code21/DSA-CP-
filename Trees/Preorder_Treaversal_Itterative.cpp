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

void preorderIterative(TreeNode *root)
{
    if (root == NULL)
        return;
    vector<int> preorder;
    stack<TreeNode *> stk;
    stk.push(root);
    while (!stk.empty())
    {
        root = stk.top();
        stk.pop();
        preorder.push_back(root->data);
        if (root->right != NULL)
            stk.push(root->right);
        if (root->left != NULL)
            stk.push(root->left);
    }
    for (int i = 0; i < preorder.size(); i++)
    {
        cout << preorder[i] << " ";
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
    preorderIterative(root);
}