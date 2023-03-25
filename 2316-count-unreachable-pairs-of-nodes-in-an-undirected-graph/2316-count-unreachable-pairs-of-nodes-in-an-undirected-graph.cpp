class Solution
{
    public:
        int dfs(int src, vector<vector < int>> &adj, vector< bool > &vis, int &cnt)
        {
            vis[src] = 1;
            cnt++;
            for (auto child: adj[src])
            {
                if (!vis[child])
                    dfs(child, adj, vis, cnt);
            }
            return cnt;
        }
    long long countPairs(int n, vector<vector < int>> &edges)
    {
        vector<vector < int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n, 0);
        long long ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, cnt);
                ans += (long long)(n - cnt) *cnt;
                cnt = 0;
            }
        }
        return ans / 2;
    }
};