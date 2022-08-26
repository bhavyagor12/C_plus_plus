#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> zigZag(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            int index = (leftToRight) ? i : (size - 1 - i);
            level[index] = node->val;
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        leftToRight = !leftToRight;
        ans.push_back(level);
    }
}
