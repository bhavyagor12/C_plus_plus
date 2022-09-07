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
public:
    bool isValidBST(TreeNode *root)
    {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
    bool isValid(TreeNode *root, long minVal, long maxVal)
    {

        if (!root)
            return true; // empty tree also a bst
        if (root->val >= maxVal || root->val <= minVal)
        {
            return false;
        }
        bool leftSide = isValid(root->left, minVal, root->val);
        bool rightSide = isValid(root->right, root->val, maxVal);
        return leftSide && rightSide;
    }
};