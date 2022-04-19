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
        void solve(TreeNode *root, vector<int> &res, int &k)
        {
            if (!root)
                return;
            solve(root->left, res, k);
            root->val = res[k];
            k++;
            solve(root->right, res, k);
        }
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    void recoverTree(TreeNode *root)
    {
        vector<int> res;
        int k = 0;
        inorder(root, res);
        sort(res.begin(), res.end());
        solve(root, res, k);
    }
};