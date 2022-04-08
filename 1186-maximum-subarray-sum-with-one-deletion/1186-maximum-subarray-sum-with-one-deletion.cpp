class Solution
{
    public:
        int maximumSum(vector<int> &nums)
        {
           	//USING DP

            int n = nums.size();
            vector<vector < int>> dp(n, vector<int> (2, 0));
            dp[0][0] = dp[0][1] = nums[0];
            int ans = nums[0];
            for (int i = 1; i < n; i++)
            {
                dp[i][0] = max(dp[i - 1][0] + nums[i], nums[i]);
                dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + nums[i]);
                ans = max({ ans,
                    dp[i][0],
                    dp[i][1] });
            }
            return ans;

           	//USING PREFIX AND SUFFIX SUM

           	// int n = nums.size();
           	// if (n == 1)
           	//     return nums[0];
           	// vector<int> pre(n, 0), suff(n, 0);
           	// pre[0] = nums[0];
           	// for (int i = 1; i < n; i++)
           	// {
           	//     pre[i] = max(pre[i - 1] + nums[i], nums[i]);
           	// }
           	// suff[n - 1] = nums[n - 1];
           	// for (int i = n - 2; i >= 0; i--)
           	// {
           	//     suff[i] = max(suff[i + 1] + nums[i], nums[i]);
           	// }
           	// int ans = max(suff[1], pre[n - 2]);
           	// for (int i = 1; i < n - 1; i++)
           	// {
           	//     ans = max(ans, pre[i - 1] + suff[i + 1]);
           	// }
           	// int curr_sum = 0;
           	// for (int i = 0; i < n; i++)
           	// {
           	//     curr_sum += nums[i];
           	//     ans = max(ans, curr_sum);
           	//     if (curr_sum < 0)
           	//         curr_sum = 0;
           	// }
           	// return ans;
        }
};