class Solution
{
    public:
       	// int solve(int idx, int buy, vector<int> &prices, vector<vector < int>> &dp)
       	// {
       	//     if (idx == prices.size())
       	//         return 0;
       	//     if (dp[idx][buy] != -1)
       	//         return dp[idx][buy];
       	//     int ans = 0;
       	//     if (buy == 1)
       	//     {
       	//         ans = max(-prices[idx] + solve(idx + 1, 0, prices, dp), solve(idx + 1, 1, prices, dp));
       	//     }
       	//     else if (buy == 0)
       	//     {
       	//         ans = max(prices[idx], solve(idx + 1, 0, prices, dp));
       	//     }
       	//     return dp[idx][buy] = ans;
       	// }
        int maxProfit(vector<int> &prices)
        {
            int n = prices.size();
           	// vector<vector < int>> dp(n + 1, vector<int> (2, -1));
           	// return solve(0, 1, prices, dp);
            int minm = prices[0], ans = 0;
            for (int i = 0; i < n; i++)
            {
                ans = max(ans, prices[i] - minm);
                minm = min(prices[i], minm);
            }
            return ans;
        }
};