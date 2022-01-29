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

void allInOneTrav(TreeNode *root)
{
    stack<pair<TreeNode *, int>> stk;
    stk.push({root, 1});
    vector<int> pre, in, post;
    if (root == NULL)
        return;
    while (!stk.empty())
    {
        auto it = stk.top();
        stk.pop();
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            stk.push(it);

            if (it.first->left != NULL)
            {
                stk.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            stk.push(it);

            if (it.first->right != NULL)
            {
                stk.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
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
}