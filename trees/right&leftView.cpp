#include <bits/stdc++.h>
using namespace std;

void rightSide(TreeNode *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (level == ans.size())
    {
        ans.push_back(root->val);
    }
    if (root->right)
    {
        rightSide(root->right, level + 1, ans);
    }
    if (root->left)
    {
        rightSide(root->left, level + 1, ans);
    }
}

void leftSide(TreeNode *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (level == ans.size())
    {
        ans.push_back(root->val);
    }
    if (root->left)
    {
        leftSide(root->left, level + 1, ans);
    }
    if (root->right)
    {
        leftSide(root->right, level + 1, ans);
    }
}
