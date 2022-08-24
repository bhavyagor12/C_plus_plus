#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
} // root left right

void postorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    cout << root->data << endl;
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    // preorderTraversal(root);
    // postorderTraversal(root);
    inorder(root);
    return 0;
}