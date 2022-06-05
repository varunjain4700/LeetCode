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
    void solve(int idx, int n, vector<vector < int>> &vis, int &ans)
    {
        if (idx == n)
        {
            ans++;
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (vis[idx][j] <= 0)
            {
               	// string str = "";
               	// for (int k = 0; k < j; k++)
               	//     str += ".";
               	// str += "Q";
               	// for (int k = j + 1; k < n; k++)
               	//     str += ".";
               	// temp.push_back(str);
                helper(idx, j, n, vis, 1);
                solve(idx + 1, n, vis, ans);
               	//temp.pop_back();
                helper(idx, j, n, vis, -1);
            }
        }
    }
    int totalNQueens(int n)
    {
        vector<vector < int>> vis(n, vector<int> (n, 0));
        int ans = 0;
        solve(0, n, vis, ans);
        return ans;
    }
};