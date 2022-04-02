class Solution
{
    public:
        int solve(int idx, int buy, vector<int> &prices, vector<vector< int>> &dp)
        {
            if (idx >= prices.size())
                return 0;
            if (dp[idx][buy] != -1)
                return dp[idx][buy];
            if (buy)
                return dp[idx][buy] = max(solve(idx + 1, 1, prices, dp), -prices[idx] + solve(idx + 1, 0, prices, dp));
            else
                return dp[idx][buy] = max(solve(idx + 1, 0, prices, dp), prices[idx] + solve(idx + 2, 1, prices, dp));
        }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector < int>> dp(n, vector<int> (2, -1));
        return solve(0, 1, prices, dp);
    }
};