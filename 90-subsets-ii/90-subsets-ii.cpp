class Solution
{
    public:
        void solve(int idx, vector<int> &nums, vector<int> &temp, vector< vector< int>> &res, int n)
        {
            if (idx == n)
            {
                res.push_back(temp);
                return;
            }
            temp.push_back(nums[idx]);
            solve(idx + 1, nums, temp, res, n);
            while (idx < n - 1 && nums[idx] == nums[idx + 1])
                idx++;
            temp.pop_back();
            solve(idx + 1, nums, temp, res, n);
        }
    vector<vector < int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> temp;
        vector<vector < int>> res;
        sort(nums.begin(), nums.end());
        solve(0, nums, temp, res, nums.size());
        return res;
    }
};