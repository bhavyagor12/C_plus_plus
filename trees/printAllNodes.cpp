/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_tracker)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
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
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        if (!root)
            return ans;

        // step 1: mark parents
        unordered_map<TreeNode *, TreeNode *> parent_tracker;
        markParents(root, parent_tracker);

        // step 2: create visited map and do BFS
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);

        visited[target] = true;
        int curr_level = 0; // equivalent to the distance

        while (!q.empty())
        {
            int size = q.size();
            if (curr_level++ == k)
                break;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if (node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if (parent_tracker[node] && !visited[parent_tracker[node]])
                {
                    q.push(parent_tracker[node]);
                    visited[parent_tracker[node]] = true;
                }
            }
        }

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            ans.push_back(node->val);
        }

        return ans;
    }
};