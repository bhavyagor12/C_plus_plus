#include <bits/stdc++.h>
using namespace std;

int findMaxDistance(TreeNode *target, unordered_map<TreeNode *, TreeNode *> &parent_tracker)
{
    queue<TreeNode *> q;
    q.push(target);
    map<TreeNode *, bool> visited;
    visited[target] = true;
    int maxi = 0; // equivalent to time
    while (!q.empty())
    {
        int size = q.size();
        int flag = 0; // flag to know the adjacent being burned
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left && !visited[node->left])
            {
                flag = 1;
                visited[node->left] = true; // mark it visited
                q.push(node->left);         // push it for next time
            }
            if (node->right && !visited[node->right])
            {
                flag = 1;
                visited[node->right] = true;
                q.push(node->right);
            }
            // check if parent exists if it exists check if viisited or no
            if (parent_tracker[node] && !visited[parent_tracker[node]])
            {
                flag = 1;
                visited[parent_tracker[node]] = true;
                q.push(parent_tracker[node]);
            }
        }
        if (flag) // if flag was set meaning burning was done hence time increase
            maxi++;
    }
    return maxi;
}

// mark parents done and return the node address of target
TreeNode *mark_parent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_tracker, int start)
{
    // start is the node where you want to burn the tree from
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *res;
    while (!q.empty())
    {
        TreeNode *node = q.front();
        if (node->val == start)
        {
            res = node;
        }
        q.pop();
        if (node->left)
        {
            parent_tracker[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            parent_tracker[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

// main function
int timeToBurn(TvoidreeNode *root, int start)
{
    unordered_map<TreeNode *, TreeNode *> parent_tracker;
    TreeNode *target = mark_parent(root, parent_tracker, start);
    int maxi = findMaxDistance(parent_tracker, target);
    return maxi;
}