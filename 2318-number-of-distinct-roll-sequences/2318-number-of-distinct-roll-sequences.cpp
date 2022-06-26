class Solution
{
    public:
        long long mod = 1e9 + 7;
    int gcd(int x, int y)
    {
        if (y > x)
            return gcd(y, x);
        if (y == 0)
            return x;
        else
            return gcd(x % y, y);
    }
    long long solve(int idx, int prev1, int prev2, int n, vector<vector<vector< long long>>> &dp)
    {
        if (idx == n)
            return 1;
        if (dp[idx][prev1][prev2] != -1)
            return dp[idx][prev1][prev2];
        long long ans = 0;
        for (int i = 1; i <= 6; i++)
        {
            if (i == prev1 || i == prev2)
                continue;
            if (prev1 == 0)
                ans += solve(idx + 1, i, prev1, n, dp);
            if (prev1 != 0)
            {
                if (gcd(i, prev1) == 1)
                    ans += solve(idx + 1, i, prev1, n, dp);
            }
        }
        return dp[idx][prev1][prev2] = ans % mod;
    }
    int distinctSequences(int n)
    {
        vector<vector<vector< long long>>> dp(n + 1, vector<vector < long long>> (7, vector < long long > (7, -1)));
        mod = 1e9 + 7;
        return solve(0, 0, 0, n, dp);
    }
};