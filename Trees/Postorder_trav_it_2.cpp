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

void postorderIterative(TreeNode *root)
{
    if (root == NULL)
        return;
    stack<TreeNode *> stk;
    vector<int> postorder;
    TreeNode *cur = root;
    while (cur != NULL || !stk.empty())
    {
        if (cur != NULL)
        {
            stk.push(cur);
            cur = cur->left;
        }
        else
        {
            TreeNode *temp = stk.top()->right;
            if (temp == NULL)
            {
                temp = stk.top();
                stk.pop();
                postorder.push_back(temp->data);
                while (!stk.empty() && temp == stk.top()->right)
                {
                    temp = stk.top();
                    stk.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                cur = temp;
            }
        }
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
    postorderIterative(root);
}