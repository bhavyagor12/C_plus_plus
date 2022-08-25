#include <bits/stdc++.h>
using namespace std;
// Time and space -- O(n);
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
vector<int> preOrder(Node *node)
{
    vector<int> preorder;
    if (node == NULL)
        return preorder;
    stack<Node *> st;
    st.push(node);
    while (!st.empty())
    {
        node = st.top();
        st.pop();
        preorder.push_back(node->data);
        if (node->right != NULL)
            st.push(node->right);
        if (node->left != NULL)
            st.push(node->left);
    }
    return preorder;
}
vector<int> inOrder(Node *node)
{
    vector<int> inorder;
    if (node == NULL)
        return inorder;
    stack<Node *> st;

    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }

    return inorder;
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    vector<int> preorderIterative = preOrder(root);
    for (auto i : preorderIterative)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> inorderIterative = inOrder(root);
    for (auto i : inorderIterative)
    {
        cout << i << " ";
    }

    return 0;
}