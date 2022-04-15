/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode * new_root;
    void solve(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return;
        solve(root->left, low, high);
        solve(root->right, low, high);
        if (root->val >= low && root->val <= high)
            new_root = root;
       	//cout << root->val << endl;
        if (root->left)
        {
            if (root->left->val < low)
                root->left = root->left->right;
            else if (root->left->val > high)
                root->left = root->left->left;
        }
        if (root->right)
        {
            if (root->right->val > high)
                root->right = root->right->left;
            else if (root->right->val < low)
                root->right = root->right->right;
        }
    }
    TreeNode* trimBST(TreeNode *root, int low, int high)
    {
        new_root = NULL;
        solve(root, low, high);
        return new_root;
    }
};