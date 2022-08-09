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
        int solve(TreeNode *root, int &l, int &r)
        {
            if (!root)
                return 0;
            int ll = 0, lr = 0, rl = 0, rr = 0;
            l = solve(root->left, ll, lr);
            r = solve(root->right, rl, rr);
            // cout << root->val << " " << l << " " << r << endl;
            // cout << ll << " " << lr << " " << rl << " " << rr << endl;
            return max(l + r, ll + lr + rl + rr + root->val);	//either choose both left and right child of the root/select the root+its grand children
        }
    int rob(TreeNode *root)
    {
        int l = 0, r = 0;
        return solve(root, l, r);
    }
};