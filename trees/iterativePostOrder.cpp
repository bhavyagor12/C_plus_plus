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

void using2Stacks(Node *node)
{
    vector<int> postorder;
    if (node == NULL)
        return;
    stack<Node *> st1, st2;
    st1.push(node);
    while (!st1.empty())
    {
        node = st1.top();
        st1.pop();
        st2.push(node);
        if (node->left != NULL)
        {
            st1.push(node->left);
        }
        if (node->right != NULL)
        {
            st1.push(node->right);
        }
    }
    while (!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    for (auto &i : postorder)
    {
        cout << i << " ";
    }
}
void using1Stack(Node *curr)
{
    vector<int> postorder;
    stack<Node *> st;
    Node *temp;
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }

    for (auto &i : postorder)
    {
        cout << i << " ";
    }
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    using1Stack(root);
    return 0;
}