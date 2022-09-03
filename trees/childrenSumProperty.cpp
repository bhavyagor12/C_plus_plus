class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                level.push_back(node->val);
            }
            double vecSize = level.size();
            double sum = 0;
            double avg;
            for (int i = 0; i < vecSize; i++)
            {
                sum += level[i];
            }

            avg = sum / vecSize;
            ans.push_back(avg);
        }
        return ans;
    }
};