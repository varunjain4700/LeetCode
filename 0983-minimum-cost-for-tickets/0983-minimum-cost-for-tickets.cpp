class Solution
{
    public:
       	//TOP-DOWN APPROACH
        int solve(vector<int> &days, vector<int> &costs, int idx, vector< int > &dp)
        {
            int n = days.size();
            if (idx >= n)
                return 0;
            if (dp[idx] != -1)
                return dp[idx];
            int cost1 = costs[0] + solve(days, costs, idx + 1, dp);	//take 1-day pass
            int i = idx, j = idx;
            for (i = idx; i < n; i++)
            {
                if (days[i] >= days[idx] + 7)
                    break;
            }
            int cost2 = costs[1] + solve(days, costs, i, dp);	//take 7-day pass
            for (j = idx; j < n; j++)
            {
                if (days[j] >= days[idx] + 30)
                    break;
            }
            int cost3 = costs[2] + solve(days, costs, j, dp);	//take 30-day pass
            return dp[idx] = min({ cost1,
                cost2,
                cost3 });
        }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(366, -1);
        return solve(days, costs, 0, dp);

       	//BOTTOM-UP APPROACH
       	//         vector<int> dp(366, 1e7);
       	//         int j = 0, n = days.size();
       	//         dp[0] = 0;

       	//         for (int i = 1; i <= 365; i++)
       	//         {
       	//             if (i == days[j])
       	//             {
       	//                	// dp[i] = dp[i - 1] + costs[0];
       	//                	// if (i < 7)
       	//                	//     dp[i] = min({ dp[i],
       	//                	//         costs[1],
       	//                	//         costs[2] });
       	//                	// else if (i >= 7 && i < 30)
       	//                	//     dp[i] = min({ dp[i],
       	//                	//         dp[i - 7] + costs[1],
       	//                	//         costs[2] });
       	//                	// else
       	//                	//     dp[i] = min({ dp[i],
       	//                	//         dp[i - 7] + costs[1],
       	//                	//         dp[i - 30] + costs[2] });
       	//                 dp[i] = min({ dp[i - 1] + costs[0],
       	//                     dp[max(0, i - 7)] + costs[1],
       	//                     dp[max(0, i - 30)] + costs[2] });
       	//                 j++;
       	//             }
       	//             else
       	//                 dp[i] = dp[i - 1];
       	//             if (i == days[n - 1])
       	//                 return dp[days[n - 1]];
       	//         }
       	//         return 0;
    }
};