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
        void solve(TreeNode *root, int sum, int &curr_sum, vector<int> &temp, vector<vector< int>> &res)
        {
            if (!root)
                return;
            curr_sum += root->val;
            temp.push_back(root->val);
            if (!root->left && !root->right)
            {
                if (curr_sum == sum)
                {
                    res.push_back(temp);
                }
            }
            solve(root->left, sum, curr_sum, temp, res);
            solve(root->right, sum, curr_sum, temp, res);
            curr_sum-=root->val;
            temp.pop_back();
        }
    vector<vector < int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector < int>> res;
        vector<int> temp;
        int curr_sum=0;
        solve(root, sum, curr_sum, temp, res);
        return res;
    }
};