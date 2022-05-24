class Solution
{
    public:
        int helper(int i, int j, int turn, vector<int> &candies, vector<vector< vector< int>>> &dp)
        {
            if (i > j)
                return 0;
            if (dp[i][j][turn] != -1)
                return dp[i][j][turn];
            if (turn == 0)
            {
                return dp[i][j][turn] = max(candies[i] + helper(i + 1, j, 1, candies, dp), candies[j] + helper(i, j - 1, 1, candies, dp));
            }
            else
            {
                return dp[i][j][turn] = min(helper(i + 1, j, 0, candies, dp), helper(i, j - 1, 0, candies, dp));
            }
        }
    bool PredictTheWinner(vector<int> &candies)
    {
        int n = candies.size();
        vector<vector<vector< int>>> dp(n, vector<vector < int>> (n, vector<int> (2, -1)));
        int player_score = helper(0, n - 1, 0, candies, dp);
        int total_score = 0;
        for (int i = 0; i < n; i++)
        {
            total_score += candies[i];
        }
        int opp_score = total_score - player_score;
        if (player_score >= opp_score)
            return true;
        return false;
    }
};