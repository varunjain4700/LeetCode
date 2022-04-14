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
        TreeNode * res;
    void solve(TreeNode *root, int key)
    {
        if (root == NULL)
            return;
        if (key == root->val)
            res = root;
        else if (key < root->val)
            solve(root->left, key);
        else
            solve(root->right, key);
    }
    TreeNode* searchBST(TreeNode *root, int val)
    {
        res = NULL;
        solve(root, val);
        return res;
    }
};