#include <bits/stdc++.h>
using namespace std;
int height(Node *root, int &maxDiameter)
{
    if (root == 0)
        return 0;
    int leftHeight = diameter(root->left, maxDiameter);
    int rightHeight = diameter(root->right, maxDiameter);
    maxDiameter = max(maxDiameter, leftHeight + rightHeight);

    return max(leftHeight, rightHeight) + 1;
}
int main()
{
    int maxDiameter = INT_MIN;
    int height = height(root, maxDiameter);

    return maxDiameter;
}