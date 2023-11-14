#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode *left, *right;
};

vector<int> getMorrisInorder(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            TreeNode *prev = cur->left;
            while (prev->right && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}

int main()
{

}