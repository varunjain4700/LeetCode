class Solution
{
    public:
       	//here color parameter denotes the color of previous house,to check whether they are of same color or not
        int solve(int idx, int color, int k, int m, int n, vector<int> &houses, vector<vector< int >> &cost, vector< vector< vector< int>>> &dp)
        {
            if (k < 0)
                return 1e7;
            if (idx == m)
            {
                if (k == 0)
                    return 0;
                else
                    return 1e7;
            }
            if (dp[idx][color][k] != -1)
                return dp[idx][color][k];
            int ans = 1e7;
            if (houses[idx] != 0)
            {
                if (houses[idx] == color)
                    ans = solve(idx + 1, houses[idx], k, m, n, houses, cost, dp);
                else
                    ans = solve(idx + 1, houses[idx], k - 1, m, n, houses, cost, dp);
            }
            else
            {
                for (int i = 1; i <= n; i++)
                {
                    if (i == color)
                        ans = min(ans, cost[idx][i - 1] + solve(idx + 1, color, k, m, n, houses, cost, dp));
                    else
                        ans = min(ans, cost[idx][i - 1] + solve(idx + 1, i, k - 1, m, n, houses, cost, dp));
                }
            }
            return dp[idx][color][k] = ans;
        }
    int minCost(vector<int> &houses, vector<vector< int>> &cost, int m, int n, int target)
    {
        vector<vector<vector< int>>> dp(m + 1, vector<vector < int>> (n + 1, vector<int> (target + 1, -1)));
        int ans = solve(0, 0, target, m, n, houses, cost, dp);
        if (ans == 1e7)
            return -1;
        return ans;
    }
};