/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    // recursive
    //  void inorder(TreeNode* root,vector<int> &ans){
    //      if(root == NULL) return;
    //      inorder(root->left,ans);
    //      ans.push_back(root->val);
    //      inorder(root->right,ans);
    //  }
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        // iterative
        //  TreeNode * node = root;
        //  stack<TreeNode*> st;
        //  while(true){
        //      if(node != NULL){
        //      st.push(node);
        //      node = node->left;
        //      }
        //      else{
        //          if(st.empty()) break;
        //          node = st.top();
        //          st.pop();
        //          ans.push_back(node->val);
        //          node = node ->right;
        //      }
        //  }
        //  inorder(root,ans);
        //  morris traversal
        if (!root)
            return ans;
        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    // create thread
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};