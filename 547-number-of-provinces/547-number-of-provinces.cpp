class Solution
{
    public:
        void dfs(int src, vector<vector < int>> &adj, vector< bool > &vis)
        {
            vis[src] = 1;
            for (auto child: adj[src])
            {
                if (!vis[child])
                    dfs(child, adj, vis);
            }
        }
    int findCircleNum(vector<vector < int>> &edges)
    {
        int n = edges.size();
        vector<vector < int>> adj(n + 1);	//adjacency list
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j != i && edges[i][j] == 1)
                    adj[i + 1].push_back(j + 1);
            }
        }
        vector<bool> vis(n + 1, 0);	//keep track of which nodes have been visited
        int cnt = 0;	//no. of connected components
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis);
                cnt++;
            }
        }
        return cnt;
    }
};