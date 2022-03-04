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

TreeNode *findlastRight(TreeNode *root)
{
    if (root->right == NULL)
        return root;
    return findlastRight(root->right);
}

TreeNode *helper(TreeNode *root)
{
    if (root->left == NULL)
        return root->right;
    if (root->right == NULL)
        return root->left;
    TreeNode *rightChild = root->right;
    TreeNode *lastRight = findlastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
    {
        return helper(root);
    }
    TreeNode *dummy = root;
    while (root != NULL)
    {
        if (root->data > key)
        {
            if (root->left != NULL && root->left->data == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
                root = root->left;
        }
        else
        {
            if (root->right != NULL && root->right->data == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
                root = root->right;
        }
    }
    return dummy;
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
    TreeNode *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 8);
    insertBST(root, 2);
    insertBST(root, 1);
    insertBST(root, 12);
    insertBST(root, 6);
    inorder(root);
    deleteNode(root, 1);
    cout << "\n";
    inorder(root);
}