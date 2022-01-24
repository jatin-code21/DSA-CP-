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

void LevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
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
    LevelOrder(root);
}