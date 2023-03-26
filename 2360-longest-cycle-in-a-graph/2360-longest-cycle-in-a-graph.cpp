class Solution
{
    public:
        void dfs(int src, vector<vector < int>> &adj, vector< bool > &vis, vector< bool > &dfs_vis, int cycle_length, int &ans, vector< int > &cnt, int &time)
        {
            vis[src] = 1;
            dfs_vis[src] = 1;
            cnt[src] = time;
            time++;
           	// cout<<src<<"-"<<cycle_length<<"--"<<cnt[src]<<endl;
            for (auto child: adj[src])
            {
                if (!vis[child])
                {
                    dfs(child, adj, vis, dfs_vis, cycle_length + 1, ans, cnt, time);
                }
                else
                {
                    if (dfs_vis[child])
                    {
                       	// cout<<child<<endl;
                        ans = max(ans, cycle_length + 1 - cnt[child]);
                    }
                }
            }
            dfs_vis[src] = 0;
        }
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<vector < int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            if (edges[i] != -1)
                adj[i].push_back(edges[i]);
        }
        vector<bool> vis(n, 0), dfs_vis(n, 0);
        vector<int> cnt(n, 0);
        int cycle_length = 0, ans = -1, time = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(i, adj, vis, dfs_vis, cycle_length, ans, cnt, time);
            time = 0;
        }
       	// cout<<endl;
        return ans;
    }
};