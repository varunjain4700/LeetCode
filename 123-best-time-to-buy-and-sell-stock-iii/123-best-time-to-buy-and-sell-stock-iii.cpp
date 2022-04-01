class Solution
{
    public:
     int dp[100001][2][2];
        int solve(int idx, int buy, int cnt, vector<int> &prices)
        {
            if (idx == prices.size() || cnt >= 2)
                return 0;
            if (dp[idx][buy][cnt] != -1)
                return dp[idx][buy][cnt];
            int profit = 0;
            if (buy == 0)
            {
                profit = max(solve(idx + 1, 0, cnt, prices), -prices[idx] + solve(idx + 1, 1, cnt, prices));
            }
            else
            {
                profit = max(solve(idx + 1, 1, cnt, prices), prices[idx] + solve(idx + 1, 0, cnt + 1, prices));
            }
            return dp[idx][buy][cnt] = profit;
        }
    int maxProfit(vector<int> &prices)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, prices);
    }
};