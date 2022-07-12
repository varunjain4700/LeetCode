class Solution
{
    public:
        int minPathSum(vector<vector < int>> &grid)
        {
            int m = grid.size(), n = grid[0].size();
           	// vector<vector < int>> dp(m, vector<int> (n, INT_MAX));
            vector<int> prev(n, INT_MAX), curr(n, INT_MAX);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == 0 && j == 0)
                    {
                        curr[j] = grid[i][j];
                        continue;
                    }
                    if (i - 1 >= 0)
                        curr[j] = prev[j];
                    if (j - 1 >= 0)
                        curr[j] = min(curr[j], curr[j - 1]);
                    curr[j] += grid[i][j];
                }
                prev = curr;
            }
            return curr[n - 1];
        }
};