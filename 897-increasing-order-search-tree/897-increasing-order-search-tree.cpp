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
        TreeNode * new_root;
    TreeNode * prev;
    void solve(TreeNode *root)
    {
        if (root == NULL)
            return;
        solve(root->left);
        if (new_root == NULL)
            new_root = root;
        else
            prev->right = root;
        prev = root;
        root->left=NULL;
        solve(root->right);
    }
    TreeNode* increasingBST(TreeNode *root)
    {
        new_root=NULL;
        solve(root);
        return new_root;
    }
};