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
        int solve(TreeNode *root, int prev_val, int &ans)
        {
            if (!root)
                return 0;
            int left = solve(root->left, root->val, ans);
            int right = solve(root->right, root->val, ans);
            ans = max(ans, left + right);
            if (root->val == prev_val)
                return 1 + max(left, right);
            else
                return 0;
        }
    int longestUnivaluePath(TreeNode *root)
    {
        int ans = 0;
        int temp = solve(root, 0, ans);
        return ans;
    }
};