class Solution
{
    public:
        int mincostTickets(vector<int> &days, vector<int> &costs)
        {
            vector<int> dp(366, 1e7);
            int j = 0, n = days.size();
            dp[0] = 0;

            for (int i = 1; i <= 365; i++)
            {
                if (i == days[j])
                {
                   	// dp[i] = dp[i - 1] + costs[0];
                   	// if (i < 7)
                   	//     dp[i] = min({ dp[i],
                   	//         costs[1],
                   	//         costs[2] });
                   	// else if (i >= 7 && i < 30)
                   	//     dp[i] = min({ dp[i],
                   	//         dp[i - 7] + costs[1],
                   	//         costs[2] });
                   	// else
                   	//     dp[i] = min({ dp[i],
                   	//         dp[i - 7] + costs[1],
                   	//         dp[i - 30] + costs[2] });
                    dp[i] = min({ dp[i - 1] + costs[0],
                        dp[max(0, i - 7)] + costs[1],
                        dp[max(0, i - 30)] + costs[2] });
                    j++;
                }
                else
                    dp[i] = dp[i - 1];
                if (i == days[n - 1])
                    return dp[days[n - 1]];
            }
            return 0;
        }
};