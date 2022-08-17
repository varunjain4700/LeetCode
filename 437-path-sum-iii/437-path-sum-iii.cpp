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
        int cnt = 0;
    void solve(TreeNode *root, int sum, long long curr_sum)
    {
        if (!root)
            return;
        curr_sum += root->val;
        if (curr_sum == sum)
            cnt++;
        solve(root->left, sum, curr_sum);
        solve(root->right, sum, curr_sum);
    }
    void preorder(TreeNode *root, int sum)
    {
        if (!root)
            return;
        solve(root, sum, 0);
        preorder(root->left, sum);
        preorder(root->right, sum);
    }

    int pathSum(TreeNode *root, int sum)
    {
        cnt = 0;
        preorder(root, sum);
        return cnt;
    }
};