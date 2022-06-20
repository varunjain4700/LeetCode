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
        int form_number(vector<int> &nums)
        {
            int n = nums.size();
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                ans += nums[i] *pow(10, i);
            }
            return ans;
        }
    void solve(TreeNode *root, vector<int> &temp, int &ans)
    {
        if (!root)
            return;
        temp.push_back(root->val);
        if (!root->left && !root->right)
        {
            reverse(temp.begin(), temp.end());
            ans += form_number(temp);
            reverse(temp.begin(), temp.end());
        }
        solve(root->left, temp, ans);
        solve(root->right, temp, ans);
        temp.pop_back();
    }
    int sumNumbers(TreeNode *root)
    {
        int ans = 0;
        vector<int> temp;
        solve(root, temp, ans);
        return ans;
    }
};