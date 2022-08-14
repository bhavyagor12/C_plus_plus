#include <bits/stdc++.h>
using namespace std;

int height(Node *root)
{
    // base condition
    if (root == NULL)
    {
        return 0;
    }
    // get left height and right height
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    // 1 is the height of itself + max height of left or right
    return 1 + max(leftHeight, rightHeight);
}