#include <bits/stdc++.h>
using namespace std;
bool isLeaf(TreeNode *root)
{
    return !root->left && root->right;
}
void addLeftBoundary(TreeNode *root, vector<int> res)
{
    TreeNode *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            res.push_back(curr->data);
        }
        if (curr->left)
            curr = curr->left;
        else
        {
            curr = curr->right;
        }
    }
}
void addRightBoundary(TreeNode *root, vector<int> &res)
{
    TreeNode *curr = curr->right;
    stack<int> st;
    while (curr)
    {
        if (isLeaf(curr))
            st.push(curr->data);
        if (curr->right)
            curr = curr->right;
        else
        {
            curr = curr->left;
        }
    }
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
}
void addLeaves(TreeNode *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}
vector<int> printBoundary(TreeNode *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}