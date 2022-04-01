class Solution
{
    public:
        int dp[1001][2][101];
    int solve(int idx, int buy, int cnt, vector<int> &prices, int k)
    {
        if (idx == prices.size() || cnt >= k)
            return 0;
        if (dp[idx][buy][cnt] != -1)
            return dp[idx][buy][cnt];
        int profit = 0;
        if (buy == 0)
        {
            profit = max(solve(idx + 1, 0, cnt, prices, k), -prices[idx] + solve(idx + 1, 1, cnt, prices, k));
        }
        else
        {
            profit = max(solve(idx + 1, 1, cnt, prices, k), prices[idx] + solve(idx + 1, 0, cnt + 1, prices, k));
        }
        return dp[idx][buy][cnt] = profit;
    }
    int maxProfit(int k, vector<int> &prices)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, prices, k);
    }
};