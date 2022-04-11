class Solution
{
    public:
        vector<vector < int>> shiftGrid(vector<vector < int>> &grid, int k)
        {
            int n = grid.size(), m = grid[0].size();
            vector<vector < int>> res(n, vector<int> (m, 0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int col = (j + k) % m;
                    int temp = max(0, (int) ceil((k - (m - j - 1)) / (double) m));
                    int row = (i + temp) % n;
                    res[row][col] = grid[i][j];
                   	//cout<<i<<","<<j<<"---"<<row<<","<<col<<endl;
                }
            }
            return res;
        }
};