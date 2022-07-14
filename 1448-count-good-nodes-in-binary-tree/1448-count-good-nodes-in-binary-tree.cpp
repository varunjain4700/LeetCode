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
        void solve(TreeNode *root, int maxm, int &cnt)
        {
            if (!root)
                return;
            if (root->val >= maxm)
                cnt++;
            solve(root->left, max(maxm, root->val), cnt);
            solve(root->right, max(maxm, root->val), cnt);
        }
    int goodNodes(TreeNode *root)
    {
        int cnt = 0, maxm = root->val;
        solve(root, maxm, cnt);
        return cnt;
    }
};