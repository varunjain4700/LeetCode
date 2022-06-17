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
        void iterative(TreeNode *root, vector<int> &postorder)
        {
            if (!root)
                return;
            stack<TreeNode*> st;
            TreeNode *curr = root;
            while (curr != NULL || !st.empty())
            {
                if (curr != NULL)
                {
                    st.push(curr);
                    curr = curr->left;
                }
                else
                {
                    TreeNode* temp = st.top()->right;
                    if (temp != NULL)
                    {
                        curr = temp;
                    }
                    else
                    {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                        while (!st.empty() && temp == st.top()->right)
                        {
                            temp = st.top();
                            st.pop();
                            postorder.push_back(temp->val);
                        }
                    }
                }
            }
        }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        iterative(root, postorder);
        return postorder;
    }
};