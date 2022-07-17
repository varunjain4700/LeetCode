class Solution
{
    public:
       	// dp[n][k] represents the number of arrays with k inverse pairs built using 1 to n
       	//dp[n][k]=dp[n-1][k]+dp[n-1][k-1]+dp[n-1][k-2]+...dp[n-1][k-(n-1)]--->1)
       	//above recurrence can be understood in a way that if n is placed at last position it will give 0 inverse pairs, so k pairs should come from rest n-1,if n is placed at second last and so on...
       	//Time complexity-O(n*k*n)-->TLE
       	//So need some kind of optimisation to above approach
       	//just put k-1 in 1) and rewrite it,
       	//dp[n][k-1]=dp[n-1][k-1]+dp[n-1][k-2]+....dp[n-1][k-1-(n-1)];---2)
       	//subtract equation 1 and 2
       	//dp[n][k]-dp[n][k-1]=dp[n-1][k]-dp[n-1][k-n];
       	//dp[n][k]=dp[n][k-1]+dp[n-1][k]-dp[n-1][k-n];
        int mod = 1e9 + 7;
    int solve(int n, int k, vector<vector < int>> &dp)
    {
        if (k < 0)
            return 0;
        if (k == 0)
            return 1;
        if (n == 0)
            return 0;
        if (dp[n][k] != -1)
            return dp[n][k];
        int ans = 0;
        ans = solve(n, k - 1, dp) + solve(n - 1, k, dp);
        ans %= mod;
        ans = (ans - solve(n - 1, k - n, dp) + mod) % mod;
        return dp[n][k] = ans;
    }
   	// int solve(int n, int k, vector<vector < int>> &dp)	//TLE
   	// {
   	//     if (k == 0)
   	//         return 1;
   	//     if (k < 0)
   	//         return 0;
   	//     if (n == 0)
   	//         return 0;
   	//     if (dp[n][k] != -1)
   	//         return dp[n][k];
   	//     int ans = 0;
   	//     for (int i = 0; i < n; i++)
   	//     {
   	//         ans += solve(n - 1, k - i, dp);
   	//         ans %= mod;
   	//     }
   	//     return dp[n][k] = ans;
   	// }
    int kInversePairs(int n, int k)
    {
        vector<vector < int>> dp(n + 1, vector<int> (k + 1, -1));
        return solve(n, k, dp);
    }
};