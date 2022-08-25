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
vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    // preorderTraversal(root);
    // postorderTraversal(root);
    // inorder(root);
    // vector<vector<int>> BFS = levelOrder(root);
    // for (int i = 0; i < BFS.size(); i++)
    // {
    //     for (int j = 0; j < BFS[i].size(); j++)
    //         cout << BFS[i][j] << " ";
    //     cout << endl;
    // }

    return 0;
}