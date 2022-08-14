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
        bool check(TreeNode *root, long long minm, long long maxm)
        {
            if (!root)
                return true;
            if (root->val <=minm || root->val >=maxm)
                return false;
            return check(root->left, minm, min((long long) root->val, maxm)) && check(root->right, max(minm, (long long) root->val), maxm);
        }
    bool isValidBST(TreeNode *root)
    {
        long long minm = -1e15, maxm = 1e15;
        return check(root, minm, maxm);
    }
};