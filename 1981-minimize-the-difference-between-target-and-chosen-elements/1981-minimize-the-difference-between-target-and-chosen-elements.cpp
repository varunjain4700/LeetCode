class Solution
{
    public:
    //very strange that if we take array instead of vector it doesn't give TLE
    int dp[70][70*70+1];
    // vector<vector < int>> dp;
        int solve(int idx, int sum, vector<vector < int>> &mat, int target)
        {
            if (idx == mat.size())
                return abs(target - sum);
            if (dp[idx][sum] != -1)
                return dp[idx][sum];
            int ans = 1e7;
            for (int i = 0; i < mat[0].size(); i++)
            {
                ans = min(ans, solve(idx + 1, sum + mat[idx][i], mat, target));
                if(ans==0)   //to avoid TLE
                    break;
            }
            return dp[idx][sum] = ans;
        }
    int minimizeTheDifference(vector<vector < int>> &mat, int target)
    {
        int m = mat.size(), n = mat[0].size(), sum = 0;
        // dp.resize(70,vector<int>(4901,-1));
         memset(dp,-1,sizeof(dp));
        //vector<vector < int>> dp(m + 1, vector<int> ((70 * 70) + 1, -1));
        return solve(0, 0, mat, target);
    }
};