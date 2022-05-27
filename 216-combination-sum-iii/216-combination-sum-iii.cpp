class Solution
{
    public:
        void solve(int idx, int k, int n, vector<int> &nums, vector<int> &temp, vector< vector< int>> &res)
        {
            if (n == 0 && k == 0)
            {
                res.push_back(temp);
                return;
            }
            if (idx == nums.size())
                return;
            if (nums[idx] <= n)
            {
                temp.push_back(nums[idx]);
                solve(idx + 1, k - 1, n - nums[idx], nums, temp, res);
                temp.pop_back();
            }
            solve(idx + 1, k, n, nums, temp, res);
        }
    vector<vector < int>> combinationSum3(int k, int n)
    {
        vector<int> nums(9, 0);
        for (int i = 1; i <= 9; i++)
            nums[i - 1] = i;
        vector<vector < int>> res;
        vector<int> temp;
        solve(0, k, n, nums, temp, res);
        return res;
    }
};