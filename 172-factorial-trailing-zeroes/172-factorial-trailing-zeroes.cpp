class Solution
{
    public:
        int trailingZeroes(int n)
        {
            int cnt = 0;
            vector<int> dp(n + 1, 0);
            for (int i = 1; i <= n; i++)
            {
                int temp = i;
                while (temp > 0 && temp % 5 == 0)
                {
                    dp[i]++;
                    temp /= 5;
                }
                dp[i] += dp[i - 1];
            }
            return dp[n];
        }
};