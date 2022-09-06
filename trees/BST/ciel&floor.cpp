int ceilValue(TreeNode *root, int key)
{
    int ceil = -1;
    while (root)
    {
        if (root->val == key)
        {
            ceil = root->val;
            return ceil;
        }
        if (root->val < key)
        {
            root = root->right;
        }
        else
        {
            ceil = root->val;
            root = root->left;
        }
    }
    return ceil;
}

int floorValue(TreeNode *root, int key)
{
    int floor = -1;
    while (root)
    {
        if (root->val == key)
        {
            ceil = root->val;
            return ceil;
        }
        if (root->val < key)
        {
            ceil = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
}