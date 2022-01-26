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

void postorder2stack(TreeNode *root)
{
    if (root == NULL)
        return;
    stack<TreeNode *> stk1, stk2;
    vector<int> postorder;
    stk1.push(root);

    while (!stk1.empty())
    {
        root = stk1.top();
        stk1.pop();
        stk2.push(root);
        if (root->left != NULL)
            stk1.push(root->left);
        if (root->right != NULL)
            stk1.push(root->right);
    }
    while (!stk2.empty())
    {
        postorder.push_back(stk2.top()->data);
        stk2.pop();
    }

    for (int i = 0; i < postorder.size(); i++)
    {
        cout << postorder[i] << " ";
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
    postorder2stack(root);
}