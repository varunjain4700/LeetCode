class Solution
{
    public:
        void dfs(int src, vector<vector < int>> &adj, vector< int > &vis)
        {
            vis[src] = 1;
            for (auto child: adj[src])
            {
                if (!vis[child])
                    dfs(child, adj, vis);
            }
        }
    int makeConnected(int n, vector<vector < int>> &connections)
    {
        int numOfCables = connections.size();
        if (numOfCables < n - 1)
            return -1;
        vector<vector < int>> adj(n);
        for (int i = 0; i < numOfCables; i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int connectedComponents = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis);
                connectedComponents++;
            }
        }
        return connectedComponents - 1;
    }
};