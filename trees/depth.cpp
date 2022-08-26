#include <bits/stdc++.h>
using namespace std;
int depthOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int maxLeft = depthOfTree(root->left);
    int maxRight = depthOfTree(root->right);
    return 1 + max(maxLeft, maxRight);
}
int main()
{
    return 0;
}