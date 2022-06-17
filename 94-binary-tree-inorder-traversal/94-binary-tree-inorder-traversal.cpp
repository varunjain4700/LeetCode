/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void iterative(TreeNode *root, vector<int> &inorder)
        {
            if (!root)
                return;
            stack<TreeNode*> st;
            TreeNode *node = root;
            while (true)
            {
                if (node)
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
                    inorder.push_back(node->val);
                    node = node->right;
                }
            }
        }
    void recursive(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
            return;
        recursive(root->left, inorder);
        inorder.push_back(root->val);
        recursive(root->right, inorder);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;
       	recursive(root,inorder);
        //iterative(root, inorder);
        return inorder;
    }
};