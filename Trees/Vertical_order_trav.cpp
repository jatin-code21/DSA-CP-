#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> todo; // {node, {vertical, level}},
    // Queue DS is taken because of level order traversal else you can take any traversal technique

    // if going left then vertical is subtracted and if right then vertical is increased
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        TreeNode *node = p.first;
        int x = p.second.first;  // vertical
        int y = p.second.second; // level
        nodes[x][y].insert(node->data);
        if (node->left)
        {
            todo.push({node->left, {x - 1, y + 1}});
        }
        if (node->right)
        {
            todo.push({node->right, {x + 1, y + 1}});
        }
        vector<vector<int>> ans;
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(21);
    root->left->right->left->right = new TreeNode(23);
}