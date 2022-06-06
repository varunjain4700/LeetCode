class Solution
{
    public:
        bool winnerSquareGame(int n)
        {
            vector<bool> dp(n + 1, 0);
            dp[0] = 0, dp[1] = 1;
            for (int i = 2; i <= n; i++)
            {
                for (int j = 1; j * j <= i; j++)
                {
                    if (dp[i - j *j] == 0)
                    {
                        dp[i] = 1;
                        break;
                    }
                }
            }
            if (dp[n])
                return true;
            return false;
        }
};