bool check(TreeNode *root, TreeNode *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return (p == q);
    }
    return (root->val == root2->val) && check(root->left, root2->left) && check(root->right, root2->right)
}