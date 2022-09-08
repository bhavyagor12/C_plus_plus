class BSTIterator
{
    stack<TreeNode *> st;

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *tmpNode = st.top();
        st.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }
};

class BSTIterator
{
    stack<TreeNode *> st;

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int before()
    {
        TreeNode *tmpNode = st.top();
        st.pop();
        pushAll(tmpNode->left);
        return tmpNode->val;
    }

    bool hasBefore()
    {
        return !st.empty();
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node)
        {
            st.push(node);
            node = node->right;
        }
    }
};
