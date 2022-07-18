class Solution
{
    public:
        int solve(vector<int> &nums, int target)
        {
            int n = nums.size();
            map<int, int> mp;
            mp[0] = 1;
            int cnt = 0, curr_sum = 0;
            for (int i = 0; i < n; i++)
            {
                curr_sum += nums[i];
                cnt += mp[curr_sum - target];
                mp[curr_sum]++;
            }
            return cnt;
        }
    int numSubmatrixSumTarget(vector<vector < int>> &mat, int target)
    {
        int m = mat.size(), n = mat[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = i; j < m; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    temp[k] += mat[j][k];
                }
                ans += solve(temp, target);	//find number of arrays with sum==target
            }
        }
        return ans;
    }
};