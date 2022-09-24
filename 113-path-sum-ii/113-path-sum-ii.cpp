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
        void solve(TreeNode *root, int &sum, int &target, vector<int> &temp, vector<vector< int>> &res)
        {
            if (!root)
                return;
            temp.push_back(root->val);
            sum += root->val;
            if (sum == target && !root->left && !root->right)
            {
                res.push_back(temp);
            }
            solve(root->left, sum, target, temp, res);
            solve(root->right, sum, target, temp, res);
            sum -= root->val;
            temp.pop_back();
        }
    vector<vector < int>> pathSum(TreeNode *root, int target)
    {
        vector<vector < int>> res;
        vector<int> temp;
        int sum = 0;
        solve(root, sum, target, temp, res);
        return res;
    }
};