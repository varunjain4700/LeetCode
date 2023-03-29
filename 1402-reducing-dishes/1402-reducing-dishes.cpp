class Solution
{
    public:
        int solve(int idx, int time, vector<int> &satisfaction, vector<vector< int>> &dp)
        {
            int n = satisfaction.size();
            if (idx >= n)
                return 0;
            if (dp[idx][time] != -1)
                return dp[idx][time];
            int take = satisfaction[idx] *time + solve(idx + 1, time + 1, satisfaction, dp);
            int notTake = solve(idx + 1, time, satisfaction, dp);
            return dp[idx][time] = max(take, notTake);
        }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector < int>> dp(n + 1, vector<int> (n + 1, -1));
        return max(0, solve(0, 1, satisfaction, dp));
    }
};