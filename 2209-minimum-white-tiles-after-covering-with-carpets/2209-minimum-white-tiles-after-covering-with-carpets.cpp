class Solution
{
    public:
       	//0---->black,,,,,1---->white
        int minimumWhiteTiles(string floor, int num, int len)
        {
            int n = floor.size();
            int dp[num + 1][n + 1];
            memset(dp, 0, sizeof(dp));
            for (int i = 1; i <= n; i++)
            {
                if (floor[i - 1] == '1')
                    dp[0][i]++;
                dp[0][i] += dp[0][i - 1];
            }
            for (int i = 1; i <= num; i++)
            {
                for (int j = 1; j <= n; j++)
                {

                    if (len >= j)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = min(dp[i - 1][j - len], dp[i][j - 1] + (floor[j - 1] - '0'));
                }
            }
            return dp[num][n];
        }
};