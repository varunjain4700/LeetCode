class Solution
{

    public:
        int dx[4] = { -1,
            0,
            0,
            1
        };
    int dy[4] = { 0,
        -1,
        1,
        0
    };
    int mod = 1e9 + 7;
    int solve(int row, int column, int moves, int m, int n, vector<vector<vector< int>>> &dp)
    {
        if (moves < 0)
            return 0;
        if (row < 0 || column < 0 || column >= n || row >= m)
            return 1;
        if (dp[row][column][moves] != -1)
            return dp[row][column][moves];
        int ans = 0;
        for (int i = 0; i < 4; i++)
        {
            ans += solve(row + dx[i], column + dy[i], moves - 1, m, n, dp);
            ans %= mod;
        }
        return dp[row][column][moves] = ans;
    }
    int findPaths(int m, int n, int moves, int row, int column)
    {
        vector<vector<vector< int>>> dp(m + 1, vector<vector < int>> (n + 1, vector<int> (moves + 1, -1)));
        return solve(row, column, moves, m, n, dp);
    }
};