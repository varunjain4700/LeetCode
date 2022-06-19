/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */

class Solution
{
    public:
        TreeNode * lca;
    void solve(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return;
        if (root->val >= p->val && root->val <= q->val)
        {
            lca = root;
            return;
        }
        solve(root->left, p, q);
        solve(root->right, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (q->val < p->val)
            swap(p, q);
        lca = NULL;
        solve(root, p, q);
        return lca;
    }
};