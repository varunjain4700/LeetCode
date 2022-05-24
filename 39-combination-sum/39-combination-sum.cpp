class Solution
{
    public:
        void solve(int idx, int target, vector<int> &nums, vector<int> &temp, vector< vector< int>> &res, int n)
        {
            if (target == 0)
            {
                res.push_back(temp);
                return;
            }
            if (idx == n)
                return;
            if (nums[idx] <= target)
            {
                temp.push_back(nums[idx]);
                solve(idx, target - nums[idx], nums, temp, res, n);
                temp.pop_back();
            }
            solve(idx + 1, target, nums, temp, res, n);
        }
    vector<vector < int>> combinationSum(vector<int> &nums, int target)
    {
        vector<int> temp;
        vector<vector < int>> res;
        solve(0, target, nums, temp, res, nums.size());
        return res;
    }
};