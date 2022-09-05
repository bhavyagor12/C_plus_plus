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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> inorder_map;
        int size = inorder.size();

        for (int i = 0; i < size; i++)
        {
            inorder_map[inorder[i]] = i;
        }

        TreeNode *root = build(postorder, 0, size - 1, inorder, 0, size - 1, inorder_map);

        return root;
    }

    TreeNode *build(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inorder_map)
    {

        if (postStart > postEnd || inStart > inEnd)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int inRoot = inorder_map[root->val];
        TreeNode *leftchild = build(postorder, postStart, postStart + inRoot - inStart - 1, inorder, inStart, inRoot - 1, inorder_map);
        TreeNode *rightchild = build(postorder, postStart + inRoot - inStart, postEnd - 1, inorder, inRoot + 1, inEnd, inorder_map);
        root->left = leftchild;
        root->right = rightchild;

        return root;
    }
};