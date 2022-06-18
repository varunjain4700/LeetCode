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
        bool balance = true;
    int solve(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        if (abs(right - left) > 1)
            balance = false;
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode *root)
    {
        balance = true;
        int temp = solve(root);
        return balance;
    }
};