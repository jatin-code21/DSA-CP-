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

TreeNode *insertBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return new TreeNode(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

TreeNode *searchinBST(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    if (key < root->data)
        return searchinBST(root->left, key);

    return searchinBST(root->right, key);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    TreeNode *root = NULL;
    root = insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 6);
    if (searchinBST(root, 10) == NULL)
        cout << "Key does not exist";
    else
        cout << "Key exist";
}