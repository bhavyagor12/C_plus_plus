#include <bits/stdc++.h>
using namespace std;

void sumProperty(TreeNode *root)
{
    if (!root)
        return 0;
    int child = 0;
    if (root->left)
    {
        child += root->left->val;
    }
    if (root->right)
    {
        child += root->right->val;
    }
    if (child >= root->val)
    {
        root->val = child;
    }
    else
    {
        if (root->left)
            root->left->val = root->val;
        else if (root->right)
            root->right->val = root->val;
    }

    sumProperty(root->left);
    sumProperty(root->right);

    int total = 0;
    if (root->left)
        total += root->left->val;
    if (root->right)
        total += root->right->val;

    if (root->left || root->right)
        root->val = total;
}