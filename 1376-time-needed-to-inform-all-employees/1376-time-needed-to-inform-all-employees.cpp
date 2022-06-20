class Solution
{
    public:
        void dfs(int src, int par, vector<vector < int>> &adj, vector< int > &informTime)
        {
            for (auto it: adj[src])
            {
                if (it != par)
                {
                    informTime[it] += informTime[src];
                    dfs(it, src, adj, informTime);
                }
            }
        }
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector < int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            if (manager[i] == -1)
                continue;
            adj[manager[i]].push_back(i);
        }
        dfs(headID, -1, adj, informTime);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
           	// cout<<informTime[i]<<" ";
            ans = max(ans, informTime[i]);
        }
       	//cout<<endl;
        return ans;
    }
};