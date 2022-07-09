/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool postorder(TreeNode *root)
        {
            if (!root)
                return true;
            bool l = postorder(root->left);
            bool r = postorder(root->right);
            if (root->val == 2)
                return l | r;
            else if (root->val == 3)
                return l &r;
            return root->val;
        }
    bool evaluateTree(TreeNode *root)
    {
        return postorder(root);
    }
};