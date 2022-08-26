#include <bits/stdc++.h>
using namespace std;
int check(Node *root)
{
    if (root == NULL)
        return 0;
    int maxLeft = check(root->left);
    int maxRight = check(root->right);
    if (maxLeft == -1 && maxRight == -1)
    {
        return -1;
    }
    if (abs(maxLeft - maxRight) > 1)
    {
        return -1;
    }
    return max(maxRight, maxLeft) + 1;
}

int main()
{
}