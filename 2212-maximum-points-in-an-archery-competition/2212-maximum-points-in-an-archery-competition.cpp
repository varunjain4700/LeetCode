class Solution
{
    public:
        vector<int> maximumBobPoints(int num, vector<int> arrows)
        {
            int dp[15][num + 1];
            memset(dp, 0, sizeof(dp));
            for (int i = 1; i <= 12; i++)
            {
                for (int j = 1; j <= num; j++)
                {
                    if (j > arrows[i - 1])
                        dp[i][j] = max(dp[i - 1][j], (i - 1) + dp[i - 1][j - (arrows[i - 1] + 1)]);
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
           	// for (int i = 0; i <= 12; i++)
           	// {
           	//     for (int j = 0; j <= num; j++)
           	//     {
           	//         cout << dp[i][j] << " ";
           	//     }
           	//     cout << endl;
           	// }
            int i = 12, j = num;
            vector<bool> present(12, 0);
            while (i >= 1 && j >= 1)
            {
                if (dp[i - 1][j] == dp[i][j])
                {
                    i--;
                }
                else
                {
                    present[i - 1] = 1;
                    j -= (arrows[i - 1] + 1);
                    i--;
                }
            }
            vector<int> res(12, 0);
            for (int i = 0; i < 12; i++)
            {
                if (present[i] == 1)
                {
                    res[i] += arrows[i] + 1;
                    num -= (arrows[i] + 1);
                }
            }
            res[0] += num;
            return res;
        }
};