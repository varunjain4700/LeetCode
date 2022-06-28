/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool solve(TreeNode *root, long minm, long maxm)
        {
            if (!root)
                return true;
           	// cout<<minm<<" "<<maxm<<" "<<root->val<<endl;
            if (root->val <= minm || root->val >= maxm)
                return false;
            return solve(root->left, minm, min(maxm, (long) root->val)) && solve(root->right, max((long) root->val, minm), maxm);
        }
    bool isValidBST(TreeNode *root)
    {
        return solve(root, -1e15, 1e15);
    }
};