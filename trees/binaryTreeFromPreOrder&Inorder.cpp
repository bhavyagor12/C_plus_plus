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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> inorder_map;
        int size = preorder.size();
        for (int i = 0; i < size; i++)
        {
            inorder_map[inorder[i]] = i;
        }
        // 7 - 0 {here 7 is the val and 0 is the index as the tree has unique values} ;

        TreeNode *root = build(preorder, 0, size - 1, inorder, 0, size - 1, inorder_map);
        return root;
    }

    TreeNode *build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inorder_map)
    {

        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = inorder_map[root->val]; // wherever the value is return the index
        int numsLeft = inRoot - inStart;

        root->left = build(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inorder_map);
        root->right = build(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inorder_map);

        return root;
    }
};