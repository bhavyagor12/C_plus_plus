class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int size = q.size();
            int mIdx = q.front().second;
            int firstIdx, lastIdx;
            for (int i = 0; i < size; i++)
            {
                long curr_idx = q.front().second - mIdx;
                TreeNode *node = q.front().first;
                q.pop();
                if (i == 0)
                    firstIdx = curr_idx;
                if (i == size - 1)
                    lastIdx = curr_idx;
                if (node->left)
                {
                    q.push({node->left, curr_idx * 2 + 1});
                }
                if (node->right)
                {
                    q.push({node->right, curr_idx * 2 + 2});
                }
            }
            ans = max(ans, (lastIdx - firstIdx + 1));
        }
        return ans;
    }
};