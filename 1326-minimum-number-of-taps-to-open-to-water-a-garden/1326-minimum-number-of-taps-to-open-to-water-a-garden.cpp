class Solution
{
    public:
        int minTaps(int n, vector<int> &ranges)
        {
           	//GREEDY
            vector<int> jumps(n + 1, 0);
            for (int i = 0; i <= n; i++)
            {
                int start = max(0, i - ranges[i]);
                int end = min(n, i + ranges[i]);
                jumps[start] = max(jumps[start], end - start);
            }
            int curr = 0, curr_end = 0, max_end = 0, ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (i > max_end)
                    return -1;
                max_end = max(max_end, i + jumps[i]);
                if (i == curr_end)
                {
                    ans++;
                    curr_end = max_end;
                }
            }
            if (max_end < n)
                return -1;
            return ans;

           	// vector < long long > dp(n + 2, INT_MAX);
           	// dp[0] = 0;
           	// for (int i = 0; i <= n; i++)
           	// {
           	//     if (ranges[i] == 0)
           	//         continue;
           	//     int start = max(0, i - ranges[i]);
           	//     int end = min(n, i + ranges[i]);
           	//     for (int k = start; k <= end; k++)
           	//     {
           	//         dp[k] = min(dp[k], dp[start] + 1);
           	//     }
           	// }
           	//	// for(int i=0;i<=n;i++)
           	//	//     cout<<dp[i]<<" ";
           	//	// cout<<endl;
           	// if (dp[n] == INT_MAX)
           	//     return -1;
           	// return dp[n];
        }
};