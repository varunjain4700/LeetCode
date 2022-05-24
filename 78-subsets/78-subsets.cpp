class Solution
{
    public:
        void solve(int idx, vector<int> &nums, vector<int> temp, vector< vector< int>> &res, int n)
        {
            if (idx == n)
            {
                res.push_back(temp);
                return;
            }
            temp.push_back(nums[idx]);
            solve(idx + 1, nums, temp, res, n);	//take 
            temp.pop_back();
            solve(idx + 1, nums, temp, res, n);	//not take      
        }
    vector<vector < int>> subsets(vector<int> &nums)
    {
        vector<int> temp;
        vector<vector < int>> res;
        solve(0, nums, temp, res, nums.size());
        return res;
    }
};