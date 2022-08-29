#include <bits/stdc++.h>
using namespace std;

bool getPath(TreeNode *root, vector<int> &ans, int val)
{
    if (!root)
    {
        return false;
    }
    ans.push_back(root->val);

    if (root->val == val)
    {
        return true;
    }
    if (getPath(root->left, ans, val) || getPath(root->right, ans, val))
    {
        return true;
    }
    ans.pop_back();
    return false;
}

int main()
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    int val;
    cin >> val;
    getPath(root, ans, val);
}