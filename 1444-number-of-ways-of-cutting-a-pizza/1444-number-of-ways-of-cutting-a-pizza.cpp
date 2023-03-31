class Solution
{
    public:
        long long dp[51][51][11];
    long long mod = 1e9 + 7;
    int find(int start_x, int start_y, int end_x, int end_y, vector<vector < int>> &cnt, int rows, int cols)
    {
        start_x++;
        start_y++;
        end_x++;
        end_y++;
        return cnt[end_x][end_y] - cnt[start_x - 1][end_y] - cnt[end_x][start_y - 1] + cnt[start_x - 1][start_y - 1];
    }
    int solve(int x, int y, int k, int &rows, int &cols, vector<string> &pizza, vector<vector< int>> &cnt)
    {
        if (x > rows || y > cols)
            return 0;
        if (k == 0)
        {
           	//check if last piece contains apple or not
            int numberOfApples = find(x, y, rows, cols, cnt, rows, cols);
            if (numberOfApples > 0)
                return 1;
            else
                return 0;
        }
        if (dp[x][y][k] != -1)
            return dp[x][y][k];
        long long ans = 0;
        for (int i = x + 1; i <= rows; i++)
        {
            int numberOfApples = find(x, y, i - 1, cols, cnt, rows, cols);
            if (numberOfApples > 0)
            {
                ans += solve(i, y, k - 1, rows, cols, pizza, cnt);
                ans %= mod;
            }
        }
        for (int i = y + 1; i <= cols; i++)
        {
            int numberOfApples = find(x, y, rows, i - 1, cnt, rows, cols);
            if (numberOfApples > 0)
            {
                ans += solve(x, i, k - 1, rows, cols, pizza, cnt);
                ans %= mod;
            }
        }
        return dp[x][y][k] = ans % mod;
    }
    int ways(vector<string> &pizza, int k)
    {
        int rows = pizza.size(), cols = pizza[0].size();
        memset(dp, -1, sizeof(dp));
       	//pre-computation for finding number of apples in a submatrix
        vector<vector < int>> cnt(rows + 1, vector<int> (cols + 1, 0));
        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= cols; j++)
            {
                if (pizza[i - 1][j - 1] == 'A')
                    cnt[i][j]++;
                cnt[i][j] += cnt[i][j - 1];
                cnt[i][j] += cnt[i - 1][j];
                cnt[i][j] -= cnt[i - 1][j - 1];
               	// cout << cnt[i][j] << " ";
            }
           	// cout << endl;
        }
        rows--;
        cols--;
        return solve(0, 0, k - 1, rows, cols, pizza, cnt);
    }
};