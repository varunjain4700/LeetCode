class Solution
{
    public:
       	//all the places queen can attack on the board
        void helper(int x, int y, int n, vector<vector < int>> &vis, int val)
        {
            for (int i = 0; i < n; i++)
            {
                vis[x][i] += val;
                vis[i][y] += val;
                if (x + i < n && y + i < n)
                    vis[x + i][y + i] += val;
                if (x + i < n && y - i >= 0)
                    vis[x + i][y - i] += val;
                if (x - i >= 0 && y + i < n)
                    vis[x - i][y + i] += val;
                if (x + i < n && y - i >= 0)
                    vis[x + i][y - i] += val;
            }
        }
    void solve(int idx, int n, vector<string> &temp, vector<vector< string >> &res, int cnt, vector< vector< int>> &vis)
    {
        if (cnt == n)
        {
            res.push_back(temp);
        }
        if (idx == n)
            return;
        for (int j = 0; j < n; j++)
        {
            if (vis[idx][j] <= 0)
            {
                string str = "";
                for (int k = 0; k < j; k++)
                    str += ".";
                str += "Q";
                for (int k = j + 1; k < n; k++)
                    str += ".";
                temp.push_back(str);
                helper(idx, j, n, vis, 1);
                solve(idx + 1, n, temp, res, cnt + 1, vis);
                temp.pop_back();
                helper(idx, j, n, vis, -1);
            }
        }
    }
    vector<vector < string>> solveNQueens(int n)
    {
        vector<vector < int>> vis(n, vector<int> (n, 0));
        vector<string> temp;
        vector<vector < string>> res;
        solve(0, n, temp, res, 0, vis);
        return res;
    }
};