class Solution
{
    public:
        void solve(int idx, int k, int n, vector<int> &temp, vector<vector< int>> &res)
        {
            if (n == 0 && k == 0)
            {
                res.push_back(temp);
                return;
            }
            if (idx == 10)
                return;
            if (idx <= n)
            {
                temp.push_back(idx);
                solve(idx + 1, k - 1, n - idx, temp, res);
                temp.pop_back();
            }
            solve(idx + 1, k, n, temp, res);
        }
    vector<vector < int>> combinationSum3(int k, int n)
    {
       	// vector<int> nums(9, 0);
       	// for (int i = 1; i <= 9; i++)
       	//     nums[i - 1] = i;
        vector<vector < int>> res;
        vector<int> temp;
        solve(1, k, n, temp, res);
        return res;
    }
};