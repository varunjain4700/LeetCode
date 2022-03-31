class Solution
{
    public:
        int dp[1001][2001];
    int solve(int idx, int k, vector<vector < int>> &piles)
    {

        if (idx == piles.size() || k == 0)
            return 0;
        if (dp[idx][k] != -1)
            return dp[idx][k];
        int ans1 = solve(idx + 1, k, piles);
        int sum = 0, ans2 = 0;
        for (int i = 0; i < min(k, (int) piles[idx].size()); i++)
        {
            sum += piles[idx][i];
            ans1 = max(ans1, sum + solve(idx + 1, k - (i + 1), piles));
        }
        dp[idx][k] = ans1;
        return dp[idx][k];
    }
    int maxValueOfCoins(vector<vector < int>> &piles, int k)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, k, piles);
    }
};