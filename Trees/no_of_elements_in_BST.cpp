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

int countNodes(TreeNode *root, int &cnt)
{
    if (root == NULL)
        return 0;
    if (root != NULL)
        cnt++;
    if (root->left != NULL)
    {
        countNodes(root->left, cnt);
    }
    if (root->right != NULL)
    {
        countNodes(root->right, cnt);
    }
    return cnt;
}

int main()
{
    TreeNode *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    int cnt = 0;
    cout << countNodes(root, cnt);
}