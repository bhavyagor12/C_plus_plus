#include <bits/stdc++.h>
using namespace std;

vector<int> TopView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<pair<TreeNode *, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode *node = p.first;
        int x = p.second;
        mp[x].insert(node->val);
        if (node->left)
        {
            q.push({node->left, x - 1});
        }
        if (node->right)
        {
            q.push({node->right, x + 1});
        }
    }
    for (auto p : mp)
    {
        ans.push_back(p.second);
    }
    return ans;
}