class Solution
{
    public:
       	//select the best two paths(maximum length) amongst all the paths starting from a node as these can only give the maximum length path.
       	//similar to finding the diameter of a tree.
        int dfs(int src, vector<vector < int>> &adj, string &s, int &ans)
        {
            int max = 0, second_max = 0;
            for (auto it: adj[src])
            {
                int temp = dfs(it, adj, s, ans);	//traversing all the child paths
                if (s[it] != s[src])
                {
                    if (temp > max)
                    {
                        second_max = max;
                        max = temp;
                    }
                    else if (temp > second_max)
                        second_max = temp;
                }
            }
            if (ans < max + second_max + 1)
                ans = max + second_max + 1;
            return 1 + max;
        }
    int longestPath(vector<int> &parent, string s)
    {
        int n = parent.size();
        vector<vector < int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == -1)
                continue;
            adj[parent[i]].push_back(i);
        }
        int ans = 1;
        dfs(0, adj, s, ans);
        return ans;
    }
};