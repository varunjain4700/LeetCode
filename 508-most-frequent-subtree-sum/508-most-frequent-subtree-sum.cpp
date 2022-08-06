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
        unordered_map<int, int> mp;
    int solve(TreeNode *root, int &maxm)
    {
        if (root == NULL)
            return 0;
        int l = solve(root->left, maxm);
        int r = solve(root->right, maxm);
        int sum = l + r + root->val;
        mp[sum]++;
        if (mp[sum] > maxm)
            maxm = mp[sum];
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        mp.clear();
        int maxm = 0;
        vector<int> res;
        int ans = solve(root, maxm);
        for (auto it: mp)
        {
            if (it.second == maxm)
                res.push_back(it.first);
        }
        return res;
    }
};