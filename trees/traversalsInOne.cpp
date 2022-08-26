#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void traversals(Node *root)
{
    vector<int> postorder, preorder, inorder;
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
            {
                cout << endl;
                st.push({it.first->right, 1});
            }
        }
        else if (it.second == 3)
        {
            postorder.push_back(it.first->data);
        }
    }
    for (auto i : postorder)
    {
        cout << i << " ";
    }
    cout << " " << endl;
    for (auto i : preorder)
    {
        cout << i << " ";
    }
    cout << " " << endl;
    for (auto i : inorder)
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
    traversals(root);
    return 0;
}