/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int ans;
    int solve(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        int temp = max(max(left, right) + root->val, root->val);
        ans = max({ ans,
            left + right + root->val,
            temp });
        return temp;
    }
    int maxPathSum(TreeNode *root)
    {
        ans = INT_MIN;
        solve(root);
        return ans;
    }
};