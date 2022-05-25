class Solution
{
    public:
        void solve(int idx, vector<int> &nums, vector<vector< int>> &res, int n)
        {
            if (idx == n)
            {
                res.push_back(nums);
                return;
            }
            for (int i = idx; i < n; i++)
            {
                swap(nums[idx], nums[i]);
                solve(idx + 1, nums, res, n);
                swap(nums[idx], nums[i]);
            }
        }
    vector<vector < int>> permute(vector<int> &nums)
    {
        vector<vector < int>> res;
        solve(0, nums, res, nums.size());
        return res;
    }
};