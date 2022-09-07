/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    void inorderTraversal(TreeNode *root, int k, int &count, int &ans)
    {
        if (!root)
            return;
        inorderTraversal(root->left, k, count, ans);
        count++;
        cout << root->val;
        if (count == k)
        {
            ans = root->val;
            return;
        }
        inorderTraversal(root->right, k, count, ans);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;
        int ans;
        inorderTraversal(root, k, count, ans);
        return ans;
    }
};