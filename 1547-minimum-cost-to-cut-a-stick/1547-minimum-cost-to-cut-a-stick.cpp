class Solution
{
    public:
        int solve(int i, int j, vector<int> &cuts, vector<vector< int>> &dp)
        {
            if (i > j)
                return 0;
            if (dp[i][j] != -1)
                return dp[i][j];
            int temp = 0, ans = 1e7;
            for (int k = i; k <= j; k++)
            {
                temp = solve(i, k - 1, cuts, dp) + solve(k + 1, j, cuts, dp) + cuts[j + 1] - cuts[i - 1];
                ans = min(ans, temp);
            }
            return dp[i][j] = ans;
        }
    int minCost(int n, vector<int> &cuts)
    {
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        vector<vector < int>> dp(m + 1, vector<int> (m + 1, -1));
        return solve(1, cuts.size() - 2, cuts, dp);
    }
};