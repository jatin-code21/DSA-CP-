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

TreeNode *inorderSucc(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

TreeNode *deleteinBST(TreeNode *root, int key)
{
    if (key < root->data)
    {
        root->left = deleteinBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteinBST(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        // case 3
        TreeNode *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteinBST(root->right, temp->data);
    }
    return root;
}

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    inorder(root);
    root = deleteinBST(root, 5);
    inorder(root);
}