if (root == NULL || root == p || root == q)
    return root;

TreeNode *leftTraversal = lowestCommonAncestor(root->left, p, q);
TreeNode *rightTraversal = lowestCommonAncestor(root->right, p, q);

if (leftTraversal == NULL)
    return rightTraversal;
else if (rightTraversal == NULL)
    return leftTraversal;
else
{
    return root;
}
