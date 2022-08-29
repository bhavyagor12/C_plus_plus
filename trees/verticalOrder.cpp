#include <bits/stdc++.h>
using namespace std;
// queue(node,vertical,level);
// map(vertical,level,{nodes});

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<pair<TreeNode *, pair<int, int>>> q;
    map<int, map<int, multiset<int>>> nodes;
    if (root == NULL)
        return ans;
    q.push({root, 0, 0});

    while (!q.empty() pair<int, int>)
    {
        auto p = q.front();
        q.pop();
        TreeNode *node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node->val);
        if (node->left)
        {
            q.push({node->left, {x - 1, y + 1}});
        }
        if (node->right)
        {
            q.push({node->right, {x + 1, y + 1}});
        }
    }
    for (auto p : nodes) // inside the map
    {
        vector<int> col;
        for (auto q : p.second) // go in the second map
        {
            col.insert(col.end(), q.second.begin(), q.second.end()); // second part is the multiset
        }
    }

    return ans;
}
