/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */

class Solution
{
    public:
        TreeNode * lca;
    void solve(TreeNode *root, int a, int b)
    {
        if (root == NULL)
            return;
        if (lca == NULL && root->val >= a && root->val <= b)
            lca = root;
        solve(root->left, a, b);
        solve(root->right, a, b);
    }
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        lca = NULL;
        int a = p->val, b = q->val;
        if (a > b)
            swap(a, b);
        solve(root, a, b);
        return lca;
    }
};