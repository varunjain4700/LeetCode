class Solution
{
    public:
        void dfs(int src, vector<vector<pair<int, int>>> &adj, vector< bool > &vis, int &res)
        {
            vis[src] = 1;
            for (auto child: adj[src])
            {
                res = min(res, child.second);
                if (!vis[child.first])
                {
                    dfs(child.first, adj, vis, res);
                }
            }
        }
    int minScore(int n, vector<vector < int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < roads.size(); i++)
        {
            adj[roads[i][0]].push_back({ roads[i][1],
                roads[i][2] });
            adj[roads[i][1]].push_back({ roads[i][0],
                roads[i][2] });
        }
        vector<bool> vis(n + 1, 0);
        int res = INT_MAX;
        dfs(1, adj, vis, res);
        return res;
    }
};